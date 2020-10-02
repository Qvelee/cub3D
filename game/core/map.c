/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 15:34:32 by nelisabe          #+#    #+#             */
/*   Updated: 2020/10/01 20:52:55 by nelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		map(t_core *game)
{
	int index;
	int sindex;
	int x;
	int y;
	
	index = -1;
	x = 0;
	y = 0;
	while (game->params->map[++index])
	{
		sindex = -1;
		while (game->params->map[index][++sindex] != '\0')
		{
			if (game->params->map[index][sindex] == '1')
				draw_block(game, x, y, 0x007700);
			else if (game->params->map[index][sindex] == ' ')
				draw_block(game, x, y, 0x000000);
			else
				draw_block(game, x, y, 0x003333);
			x += game->map.block_size;
		}
		y += game->map.block_size;
		x = 0;
	}
	return (0);
}