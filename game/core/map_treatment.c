/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_treatment.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 19:17:50 by nelisabe          #+#    #+#             */
/*   Updated: 2020/10/24 13:48:43 by nelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_spr(t_sprite *sprite, double x, double y, double z)
{
	sprite->x = x;
	sprite->y = y;
	sprite->z = z;
}

void	place_on_map(t_core *game, double x, double y, char object)
{
	int	x_in_map;
	int y_in_map;

	x_in_map = (int)x;
	y_in_map = (int)y;
	if (y_in_map > game->map.map_lines - 1 || \
		x_in_map > game->map.map_colunms - 1)
		return ;
	if (y_in_map < 0 || x_in_map < 0)
		return ;
	game->params->map[y_in_map][x_in_map] = object;
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
		if (game->params->map[y_in_map][x_in_map] == 'd' || \
			game->params->map[y_in_map][x_in_map] == 'b' || \
			game->params->map[y_in_map][x_in_map] == '2' || \
			game->params->map[y_in_map][x_in_map] == 'p' || \
			game->params->map[y_in_map][x_in_map] == 's')
			result = 1;
	return (result);
}
