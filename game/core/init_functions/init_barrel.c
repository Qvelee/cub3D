/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_barrel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 15:26:00 by nelisabe          #+#    #+#             */
/*   Updated: 2020/10/24 14:21:18 by nelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	set_barrels(t_core *game, t_object *barrel)
{
	barrel->pos[0].volume = 0;
	barrel->pos[0].a_tmp = 0;
	barrel->pos[0].a_speed = 8;
	barrel->pos[0].type = 'b';
	barrel->pos[0].scale_x = 0.5;
	barrel->pos[0].scale_y = 0.7;
	set_spr(&barrel->pos[0], 2.6, 11.6, 0.25);
	place_on_map(game, 2.6, 11.6, barrel->pos[0].type);
	create_anim_buff(game, barrel->anim, &barrel->pos[0].a_buff, 13);
	barrel->pos[1].volume = 0;
	barrel->pos[1].a_tmp = 0;
	barrel->pos[1].a_speed = 11;
	barrel->pos[1].type = 'b';
	barrel->pos[1].scale_x = 0.5;
	barrel->pos[1].scale_y = 0.6;
	set_spr(&barrel->pos[1], 2.6, 11.2, 0.15);
	place_on_map(game, 2.2, 11.2, barrel->pos[1].type);
	create_anim_buff(game, barrel->anim, &barrel->pos[1].a_buff, 13);
}

void	init_barrel(t_core *game, char *path)
{
	const int	anim_img_quant = 13;

	if (!(game->barrel.anim = (t_tex*)malloc(sizeof(t_tex) * \
		(anim_img_quant + 1))))
		error_malloc(game);
	init_load_anim_images(game, &game->barrel, path, anim_img_quant);
	game->barrel.quantity = 2;
	if (!(game->barrel.pos = (t_sprite*)malloc(sizeof(t_sprite) * \
		game->barrel.quantity)))
		error_malloc(game);
	init_a_buff(&game->barrel, game->barrel.quantity);
	set_barrels(game, &game->barrel);
}
