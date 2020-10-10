/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 14:00:56 by nelisabe          #+#    #+#             */
/*   Updated: 2020/10/10 17:06:19 by nelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//add malloc protect

void	set_spr(t_sprite *sprite, double x, double y, double z)
{
	sprite->x = x;
	sprite->y = y;
	sprite->z = z;
}

void	init_devil(t_core *game, char *path)
{
	int			quantity;
	
	quantity = -1;
	game->devil.tex = (t_tex*)malloc(sizeof(t_tex) * 8);
	while (++quantity < 8)
		load_image(game, &game->devil.tex[quantity], \
			ft_strjoin(path, ft_strjoin(ft_itoa(quantity), ".xpm")));
	game->devil.quantity = 3;
	game->devil.pos = (t_sprite*)malloc(sizeof(t_sprite) * \
		game->devil.quantity);
	game->devil.pos[0].condition = 1;
	game->devil.pos[0].type = 'd';
	game->devil.pos[0].scale = 1;
	set_spr(&game->devil.pos[0], 2.5, 1.5, 0.5);
	game->devil.pos[1].condition = 1;
	game->devil.pos[1].type = 'd';
	game->devil.pos[1].scale = 0.3;
	set_spr(&game->devil.pos[1], 6.1, 2.9, 0.5);
}

void	init_sprites(t_core *game)
{
	init_basic(game, game->params->s);
	init_devil(game, "./sprites/devil/");
}