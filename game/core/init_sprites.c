/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 14:00:56 by nelisabe          #+#    #+#             */
/*   Updated: 2020/10/06 21:58:22 by nelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//add malloc protect

void	find_sprites(t_object *sprite, char **map, char type)
{
	int	x_in_map;
	int	y_in_map;
	int	temp;

	y_in_map = -1;
	while (map[++y_in_map])
	{
		x_in_map = -1;
		while (map[y_in_map][++x_in_map])
			if (map[y_in_map][x_in_map] == type)
				sprite->quantity++;
	}
	y_in_map = -1;
	sprite->pos = (t_sprite*)malloc(sizeof(t_sprite) * sprite->quantity);
	temp = -1;
	while (map[++y_in_map])
	{
		x_in_map = -1;
		while (map[y_in_map][++x_in_map])
			if (map[y_in_map][x_in_map] == type)
			{
				sprite->pos[++temp].x = (double)x_in_map + 0.5;
				sprite->pos[temp].y = (double)y_in_map + 0.5;
				sprite->pos[temp].z = 0.5;
				sprite->pos[temp].type = type;
			}
	}	
}

void	init_basic(t_core *game, char *path)
{
	game->basic.tex = (t_tex*)malloc(sizeof(t_tex) * 1);
	load_image(game, &game->basic.tex[0], ft_strjoin(path, "3.xpm"));
	game->basic.quantity = 0;
	find_sprites(&game->basic, game->params->map, '2');
}

void	init_sprites(t_core *game)
{
	init_basic(game, "./sprites/2/");
}