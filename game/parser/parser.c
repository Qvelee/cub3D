/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 13:57:04 by nelisabe          #+#    #+#             */
/*   Updated: 2020/08/25 18:30:25 by nelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../core/cub3D.h"

static	int		is_valid_par(char *line)
{
	const char *vpars[8] = {"R ", "NO ", "SO ", "WE ", "EA ", "S ", "F ", "C "};
	int index;
	int sindex;

	index = -1;
	while (++index < 8)
		if (ft_strnstr(line, vpars[index], 2))
			return (index + 1);
	return (0);
}

static	int		get_pars(char *line, t_pars *params)
{
	int temp;

	if ((temp = is_valid_par(line)))
		
	return (0);
}

static	int		get_lines(char *path, t_pars *params)
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
	return (0);
}

int				parser(char *path, t_pars *params)
{
	
	return (0);
}