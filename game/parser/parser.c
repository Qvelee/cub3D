/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 13:57:04 by nelisabe          #+#    #+#             */
/*   Updated: 2020/09/01 14:03:15 by nelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void print_struct(t_pars *params)
{
	printf("resolution - %4d %4d\n", params->r[0], params->r[1]);
	printf("north - %20s\n", params->no);
	printf("south - %20s\n", params->so);
	printf("west  - %20s\n", params->we);
	printf("east  - %20s\n", params->ea);
	printf("floor - %d,%d,%d\n", params->f[0], params->f[1], params->f[2]);
	printf("ceiling - %d,%d,%d\n", params->c[0], params->c[1], params->c[2]);
}

static int get_pars(char *line, t_pars *params)
{
	const char *vpars[8] = {"R ", "NO ", "SO ", "WE ", "EA ", "S ", "F ", "C "};
	int index;

	index = -1;
	while (++index < 8)
		if (ft_strnstr(line, vpars[index], 3))
			return (upd_pars(index, ft_strchr(line, ' ') + 1, params));
	if (*line == 1 || *line == ' ' || *line == 0)
		return (2);
	else
		return (0);
}

int parser(char *path, t_pars *params)
{
	int fd;
	int error;
	char *line;

	fd = open(path, O_RDONLY);
	line = NULL;
	while ((error = get_next_line(fd, &line)))
	{
		if (error == -1)
			return (1);
		if (get_pars(line, params) == 2)
			map_solve(fd, line);
		else
			printf("error in params file\n");
		free(line);
	}
	print_struct(params);
	free(line);
	close(fd);
	return (0);
}
