/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 13:57:04 by nelisabe          #+#    #+#             */
/*   Updated: 2020/08/26 16:37:44 by nelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../core/cub3D.h"
#include "parser.h"
static	int		get_pars(char *line, t_pars *params)
{
	const char *vpars[8] = {"R ", "NO ", "SO ", "WE ", "EA ", "S ", "F ", "C "};
	int index;

	index = -1;
	while (++index < 8)
		if (ft_strnstr(line, vpars[index], 3))
			if (upd_pars(index, ft_strchr(line, ' ') + 1, params))
				return (1);
			else
				break ;
	return (0);
}

int				parser(char *path, t_pars *params)
{
	int		fd;
	int		error;
	char	*line;

	fd = open(path, O_RDONLY);
	line = NULL;
	while ((error = get_next_line(fd, &line)))
	{
		if (error == -1)
			return (1);
		get_pars(line, &params);
		free(line);
	}
	free (line);
	close(fd);
	return (0);
}
