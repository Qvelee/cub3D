/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_treatment.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 19:17:50 by nelisabe          #+#    #+#             */
/*   Updated: 2020/10/19 20:23:16 by nelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_wall_type(t_core *game, double x, double y, char object)
{
	int x_in_map;
	int	y_in_map;
	int	result;

	x_in_map = x / game->map.block_size;
	y_in_map = y / game->map.block_size;
	result = 0;
	if (y_in_map > game->map.map_lines - 1 || \
		x_in_map > game->map.map_colunms - 1)
		return (1);
	if (y_in_map < 0 || x_in_map < 0)
		return (1);
	if (game->params->map[y_in_map][x_in_map] == object || \
		game->params->map[y_in_map][x_in_map] == '\0')
			result = 1;
	return (result);
}

int		object_check(t_core *game, double x, double y, char object)
{
	int x_in_map;
	int	y_in_map;
	int	result;

	x_in_map = x / game->map.block_size;
	y_in_map = y / game->map.block_size;
	result = 0;
	if (y_in_map > game->map.map_lines - 1 || \
		x_in_map > game->map.map_colunms - 1)
		return (1);
	if (y_in_map < 0 || x_in_map < 0)
		return (1);
	if (object == 'W' || object == 'A')
		if (game->params->map[y_in_map][x_in_map] == '1' || \
			game->params->map[y_in_map][x_in_map] == '\0')
			result = 1;
	if ((object == 'S' || object == 'A') && !result)
		if (game->params->map[y_in_map][x_in_map] == '2')
			result = 1;
	return (result);
}
