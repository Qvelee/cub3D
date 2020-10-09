/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 14:00:56 by nelisabe          #+#    #+#             */
/*   Updated: 2020/10/09 20:58:36 by nelisabe         ###   ########.fr       */
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

// void	init_basic(t_core *game, char *path)
// {
// 	game->basic.tex = (t_tex*)malloc(sizeof(t_tex) * 1);
// 	load_image(game, &game->basic.tex[0], ft_strjoin(path, "3.xpm"));
// 	game->basic.quantity = 0;
// 	game->basic.condition = 0;
// 	find_sprites(&game->basic, game->params->map, '2');
// }

void	init_devil(t_core *game, char *path)
{
	int			quantity;
	
	quantity = -1;
	game->basic.tex = (t_tex*)malloc(sizeof(t_tex) * 8);
	while (++quantity < 8)
		load_image(game, &game->basic.tex[quantity], \
			ft_strjoin(path, ft_strjoin(ft_itoa(quantity), ".xpm")));
	game->devil.quantity = 1;
	game->devil.condition = 1;
	find_sprites(&game->basic, game->params->map, '2');
	// game->devil.pos = (t_sprite*)malloc(sizeof(t_sprite) * \
	// 	game->devil.quantity);
	// game->devil.pos[0].x = 5.5;
	// game->devil.pos[0].y = 4.5;
	// game->devil.pos[0].z = 0.5;
	// game->devil.pos[0].type = 'd';
}

void	init_sprites(t_core *game)
{
	//init_basic(game, "./sprites/2/");
	init_devil(game, "./sprites/devil/");
}