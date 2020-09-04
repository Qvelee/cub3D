/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_managment_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 20:16:15 by nelisabe          #+#    #+#             */
/*   Updated: 2020/09/04 16:21:30 by nelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

int		error_color_par_not_correct(char *line, t_pars *params)
{
	free_struct(params);
	ft_putstr_fd("cub3D: This line \"", 1);
	ft_putstr_fd(line, 1);
	ft_putendl_fd("\" is not correct", 1);
	return (0);
}

int		error_r_par_not_correct(char *line)
{
	ft_putstr_fd("cub3D: This line \"", 1);
	ft_putstr_fd(line, 1);
	ft_putendl_fd("\" is not correct", 1);
	return (0);
}

int		error_malloc_ltm_map(t_list **map)
{
	ft_lstclear(map, free);
	ft_putendl_fd("cub3D: Memory allocation fail", 1);
	return (0);
}

int		error_malloc_map(char **tmplastl)
{
	free(*tmplastl);
	ft_putendl_fd("cub3D: Memory allocation fail", 1);
	return (0);
}

int		error_malloc_tmplastl(void)
{
	ft_putendl_fd("cub3D: Memory allocation fail", 1);
	return (0);
}

int		error_read_file_get_lines(int fd, t_list **map)
{
	close(fd);
	ft_lstclear(map, free);
	ft_putendl_fd("cub3D: Error while reading from file", 1);
	return (-1);
}

int		error_malloc_tmplst(char **line, char **tmpdup, t_list **map)
{
	free(*line);
	free(*tmpdup);
	ft_lstclear(map, free);
	ft_putendl_fd("cub3D: Memory allocation fail", 1);
	return (0);
}

int		error_malloc_tmpdup(char **line, t_list **map)
{
	free(*line);
	ft_lstclear(map, free);
	ft_putendl_fd("cub3D: Memory allocation fail", 1);
	return (0);
}

int		error_get_map(char **line, int fd, int error)
{
	int temp;

	if (error == -1)
	{
		free(*line);
		return (0);
	}
	free(*line);
	while ((temp = get_next_line(fd, line)))
	{
		if (temp == -1)
			break ;
		free(*line);
	}
	free(*line);
	close(fd);
	return (0);
}

int		error_get_lines(t_pars *params)
{
	free_struct(params);
	return (0);
}