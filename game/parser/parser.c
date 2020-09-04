/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 13:57:04 by nelisabe          #+#    #+#             */
/*   Updated: 2020/09/04 19:09:26 by nelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	init(char **line, t_pars *params)
{
	*line = NULL;
	params->no = NULL;
	params->so = NULL;
	params->we = NULL;
	params->ea = NULL;
	params->s = NULL;
	params->map = NULL;
	params->f[0] = 666;
	params->c[0] = 666;
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
			return (!error_read_file_pars(fd, params));
		if (!(temp = get_pars(line, params)))
			return (!error_get_pars(&line, fd));
		if (temp == 2)
			if (!(temp = get_map(fd, line, params)) || temp == -1)
				return (!error_get_map(&line, fd, temp));
		free(line);
	}
	free(line);
	close(fd);
	return (0);
}
