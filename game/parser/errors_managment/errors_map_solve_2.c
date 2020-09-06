/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_map_solve_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 14:56:22 by nelisabe          #+#    #+#             */
/*   Updated: 2020/09/06 14:59:39 by nelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

int		error_malloc_ltm_mindex(t_list **map, t_pars *params)
{
	int		index;
	
	index = -1;
	ft_lstclear(map, free);
	while (params->map[++index])
		free(params->map[index]);
	free(params->map);
	ft_putendl_fd("cub3D: Memory allocation fail", 1);
	return (0);
}

int		error_malloc_ltm_map(t_list **map)
{
	ft_lstclear(map, free);
	ft_putendl_fd("cub3D: Memory allocation fail", 1);
	return (0);
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
