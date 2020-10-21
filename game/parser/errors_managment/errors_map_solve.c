/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_map_solve.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 14:42:25 by nelisabe          #+#    #+#             */
/*   Updated: 2020/10/21 19:20:56 by nelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

int		error_read_file_get_lines(int fd, t_list **map)
{
	close(fd);
	ft_lstclear(map, free);
	ft_putendl_fd("Error", 1);
	ft_putendl_fd("cub3D: Error while reading from file", 1);
	return (-1);
}

int		error_malloc_map(char **tmplastl)
{
	free(*tmplastl);
	ft_putendl_fd("Error", 1);
	ft_putendl_fd("cub3D: Memory allocation fail", 1);
	return (0);
}

int		error_malloc_tmplastl(void)
{
	ft_putendl_fd("Error", 1);
	ft_putendl_fd("cub3D: Memory allocation fail", 1);
	return (0);
}

int		error_not_valid_map(t_pars *params)
{
	int		index;

	index = -1;
	free_struct(params);
	while (params->map[++index])
		free(params->map[index]);
	free(params->map);
	ft_putendl_fd("Error", 1);
	ft_putendl_fd("cub3D: Invalid map", 1);
	return (0);
}

int		error_get_lines(t_pars *params)
{
	free_struct(params);
	return (0);
}
