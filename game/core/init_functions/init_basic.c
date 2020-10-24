/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_basic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 14:51:37 by nelisabe          #+#    #+#             */
/*   Updated: 2020/10/24 14:57:34 by nelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static	void	find_quantity(t_object *sprite, char **map, char type)
{
	int	x_in_map;
	int	y_in_map;

	y_in_map = -1;
	while (map[++y_in_map])
	{
		x_in_map = -1;
		while (map[y_in_map][++x_in_map])
			if (map[y_in_map][x_in_map] == type)
				sprite->quantity++;
	}
}

static	void	find_sprites(t_core *game, t_object *sprite, \
	char **map, char type)
{
	int	x_in_map;
	int	y_in_map;
	int	temp;

	find_quantity(sprite, map, type);
	y_in_map = -1;
	if (!(sprite->pos = (t_sprite*)malloc(sizeof(t_sprite) * \
		sprite->quantity)))
		error_malloc(game);
	temp = -1;
	while (map[++y_in_map])
	{
		x_in_map = -1;
		while (map[y_in_map][++x_in_map])
			if (map[y_in_map][x_in_map] == type)
			{
				set_spr(&sprite->pos[++temp], (double)x_in_map + 0.5, \
					(double)y_in_map + 0.5, 0.5);
				sprite->pos[temp].volume = 0;
				sprite->pos[temp].scale_x = 1;
				sprite->pos[temp].scale_y = 1;
				sprite->pos[temp].type = type;
				sprite->pos[temp].a_buff = NULL;
			}
	}
}

void			init_basic(t_core *game, char *path)
{
	if (!(game->basic.tex = (t_tex*)malloc(sizeof(t_tex) * 2)))
		error_malloc(game);
	game->basic.tex[1].img.image = NULL;
	load_image(game, &game->basic.tex[0], path);
	game->basic.quantity = 0;
	find_sprites(game, &game->basic, game->params->map, '2');
}
