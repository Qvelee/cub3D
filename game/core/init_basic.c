/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_basic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 14:51:37 by nelisabe          #+#    #+#             */
/*   Updated: 2020/10/10 17:06:08 by nelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	void	find_qantity(t_object *sprite, char **map, char type)
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
}

static	void	find_sprites(t_object *sprite, char **map, char type)
{
	int	x_in_map;
	int	y_in_map;
	int	temp;

	find_qantity(sprite, map, type);
	y_in_map = -1;
	sprite->pos = (t_sprite*)malloc(sizeof(t_sprite) * sprite->quantity);
	temp = -1;
	while (map[++y_in_map])
	{
		x_in_map = -1;
		while (map[y_in_map][++x_in_map])
			if (map[y_in_map][x_in_map] == type)
			{
				set_spr(&sprite->pos[++temp], (double)x_in_map + 0.5, \
					(double)y_in_map + 0.5, 0.5);
				sprite->pos[temp].scale = 1;
				sprite->pos[temp].type = type;
				sprite->pos[temp].condition = 0;
			}
	}	
}

void			init_basic(t_core *game, char *path)
{
	game->basic.tex = (t_tex*)malloc(sizeof(t_tex) * 1);
	load_image(game, &game->basic.tex[0], path);
	game->basic.quantity = 0;
	find_sprites(&game->basic, game->params->map, '2');
}
