/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 13:57:04 by nelisabe          #+#    #+#             */
/*   Updated: 2020/09/03 19:47:59 by nelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void print_struct(t_pars *params)
{
	int index;

	printf("resolution - %4d %4d\n", params->r[0], params->r[1]);
	printf("north - %20s\n", params->no);
	printf("south - %20s\n", params->so);
	printf("west  - %20s\n", params->we);
	printf("east  - %20s\n", params->ea);
	printf("floor - %d,%d,%d\n", params->f[0], params->f[1], params->f[2]);
	printf("ceiling - %d,%d,%d\n", params->c[0], params->c[1], params->c[2]);
	index = -1;
	while (params->map[++index])
		printf("%s\n", params->map[index]);
}

static void	init(char **line, t_pars *params)
{
	*line = NULL;
	params->no = NULL;
	params->so = NULL;
	params->we = NULL;
	params->ea = NULL;
	params->s = NULL;
	params->map = NULL;
}

static int get_pars(char *line, t_pars *params)
{
	const char *vpars[8] = {"R ", "NO ", "SO ", "WE ", "EA ", "S ", "F ", "C "};
	int index;

	index = -1;
	while (++index < 8)
		if (ft_strnstr(line, vpars[index], 3))
			return (upd_pars(index, ft_strchr(line, ' ') + 1, params));
	if (*line == '\0')
		return (1);
	if (*line == '1' || *line == ' ')
		return (2);
	return (error_invalid_params(params));
}

int			parser(char *path, t_pars *params)
{
	int fd;
	int temp;
	char *line;

	if ((fd = open(path, O_RDONLY)) == -1)
		perror("cub3D");
	init(&line, params);
	while ((temp = get_next_line(fd, &line)))
	{
		if (temp == -1)
			return (error_reading_file(&line, fd, params));
		if (!(temp = get_pars(line, params)))
			return (error_get_pars(&line, fd));
		if (temp == 2)
			if (!map_solve(fd, line, params))
				return (3);
		free(line);
	}
	print_struct(params);
	free(line);
	close(fd);
	return (0);
}
