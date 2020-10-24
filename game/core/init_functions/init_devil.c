/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_devil.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 18:18:03 by nelisabe          #+#    #+#             */
/*   Updated: 2020/10/24 14:21:27 by nelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	set_more_devils_3(t_core *game, t_object *devil)
{
	devil->pos[6].volume = 1;
	devil->pos[6].a_tmp = 0;
	devil->pos[6].a_speed = 2;
	devil->pos[6].type = 'd';
	devil->pos[6].scale_x = 1;
	devil->pos[6].scale_y = 1;
	set_spr(&devil->pos[6], 7.5, 4.6, 0.5);
	place_on_map(game, 7.5, 4.5, devil->pos[6].type);
	create_anim_buff(game, devil->anim, &devil->pos[6].a_buff, 14);
}

void	set_more_devils_2(t_core *game, t_object *devil)
{
	devil->pos[4].volume = 1;
	devil->pos[4].a_tmp = 0;
	devil->pos[4].a_speed = 2;
	devil->pos[4].type = 'd';
	devil->pos[4].scale_x = 0.7;
	devil->pos[4].scale_y = 0.7;
	set_spr(&devil->pos[4], 9.6, 2.6, 0.5);
	place_on_map(game, 9.6, 2.6, devil->pos[4].type);
	create_anim_buff(game, devil->anim, &devil->pos[4].a_buff, 14);
	devil->pos[5].volume = 1;
	devil->pos[5].a_tmp = 0;
	devil->pos[5].a_speed = 2;
	devil->pos[5].type = 'd';
	devil->pos[5].scale_x = 0.5;
	devil->pos[5].scale_y = 0.5;
	set_spr(&devil->pos[5], 8, 2.6, 1.3);
	place_on_map(game, 7.6, 2.6, devil->pos[5].type);
	create_anim_buff(game, devil->anim, &devil->pos[5].a_buff, 14);
	set_more_devils_3(game, devil);
}

void	set_more_devils(t_core *game, t_object *devil)
{
	devil->pos[2].volume = 1;
	devil->pos[2].a_tmp = 0;
	devil->pos[2].a_speed = 2;
	devil->pos[2].type = 'd';
	devil->pos[2].scale_x = 1.6;
	devil->pos[2].scale_y = 1.6;
	set_spr(&devil->pos[2], 7.2, 1.6, 0.9);
	place_on_map(game, 6.6, 1.6, devil->pos[2].type);
	create_anim_buff(game, devil->anim, &devil->pos[2].a_buff, 14);
	devil->pos[3].volume = 1;
	devil->pos[3].a_tmp = 0;
	devil->pos[3].a_speed = 2;
	devil->pos[3].type = 'd';
	devil->pos[3].scale_x = 1;
	devil->pos[3].scale_y = 1;
	set_spr(&devil->pos[3], 6.6, 2.6, 0.5);
	place_on_map(game, 6.6, 2.6, devil->pos[3].type);
	create_anim_buff(game, devil->anim, &devil->pos[3].a_buff, 14);
	set_more_devils_2(game, devil);
}

void	set_devils(t_core *game, t_object *devil)
{
	devil->pos[0].volume = 1;
	devil->pos[0].a_tmp = 0;
	devil->pos[0].a_speed = 3;
	devil->pos[0].type = 'd';
	devil->pos[0].scale_x = 1;
	devil->pos[0].scale_y = 1;
	set_spr(&devil->pos[0], 9.6, 1.6, 0.5);
	place_on_map(game, 9.6, 1.6, devil->pos[0].type);
	create_anim_buff(game, devil->anim, &devil->pos[0].a_buff, 14);
	devil->pos[1].volume = 1;
	devil->pos[1].a_tmp = 0;
	devil->pos[1].a_speed = 1;
	devil->pos[1].type = 'd';
	devil->pos[1].scale_x = 1.1;
	devil->pos[1].scale_y = 1.1;
	set_spr(&devil->pos[1], 8.6, 1.6, 0.8);
	place_on_map(game, 8.6, 1.6, devil->pos[1].type);
	create_anim_buff(game, devil->anim, &devil->pos[1].a_buff, 14);
	set_more_devils(game, devil);
}

void	init_devil(t_core *game, char *path)
{
	const int	base_img_quant = 8;
	const int	anim_img_quant = 14;

	if (!(game->devil.tex = (t_tex*)malloc(sizeof(t_tex) * \
		(base_img_quant + 1))))
		error_malloc(game);
	init_load_tex_images(game, &game->devil, path, base_img_quant);
	if (!(game->devil.anim = (t_tex*)malloc(sizeof(t_tex) * \
		(anim_img_quant + 1))))
		error_malloc(game);
	init_load_anim_images(game, &game->devil, path, anim_img_quant);
	game->devil.quantity = 7;
	if (!(game->devil.pos = (t_sprite*)malloc(sizeof(t_sprite) * \
		game->devil.quantity)))
		error_malloc(game);
	init_a_buff(&game->devil, game->devil.quantity);
	set_devils(game, &game->devil);
}
