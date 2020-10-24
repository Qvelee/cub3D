/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fire.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 18:34:55 by nelisabe          #+#    #+#             */
/*   Updated: 2020/10/24 14:21:24 by nelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	set_more_fires_2(t_core *game, t_object *fire)
{
	fire->pos[6].volume = 0;
	fire->pos[6].a_tmp = 0;
	fire->pos[6].a_speed = 1;
	fire->pos[6].type = 'f';
	fire->pos[6].scale_x = 0.9;
	fire->pos[6].scale_y = 0.9;
	set_spr(&fire->pos[6], 15.6, 2.7, 0.5);
	create_anim_buff(game, fire->anim, &fire->pos[6].a_buff, 16);
	fire->pos[7].volume = 0;
	fire->pos[7].a_tmp = 0;
	fire->pos[7].a_speed = 2;
	fire->pos[7].type = 'f';
	fire->pos[7].scale_x = 0.5;
	fire->pos[7].scale_y = 0.5;
	set_spr(&fire->pos[7], 16.6, 1.9, 0.15);
	create_anim_buff(game, fire->anim, &fire->pos[7].a_buff, 16);
	fire->pos[8].volume = 0;
	fire->pos[8].a_tmp = 0;
	fire->pos[8].a_speed = 2;
	fire->pos[8].type = 'f';
	fire->pos[8].scale_x = 0.8;
	fire->pos[8].scale_y = 0.8;
	set_spr(&fire->pos[8], 17.4, 6.4, 0.4);
	create_anim_buff(game, fire->anim, &fire->pos[8].a_buff, 16);
}

void	set_more_fires(t_core *game, t_object *fire)
{
	fire->pos[3].volume = 0;
	fire->pos[3].a_tmp = 0;
	fire->pos[3].a_speed = 1;
	fire->pos[3].type = 'f';
	fire->pos[3].scale_x = 1.8;
	fire->pos[3].scale_y = 2.2;
	set_spr(&fire->pos[3], 13.6, 2.6, 0.7);
	create_anim_buff(game, fire->anim, &fire->pos[3].a_buff, 16);
	fire->pos[4].volume = 0;
	fire->pos[4].a_tmp = 0;
	fire->pos[4].a_speed = 2;
	fire->pos[4].type = 'f';
	fire->pos[4].scale_x = 0.5;
	fire->pos[4].scale_y = 0.5;
	set_spr(&fire->pos[4], 16.1, 2.6, 0.15);
	create_anim_buff(game, fire->anim, &fire->pos[4].a_buff, 16);
	fire->pos[5].volume = 0;
	fire->pos[5].a_tmp = 0;
	fire->pos[5].a_speed = 2;
	fire->pos[5].type = 'f';
	fire->pos[5].scale_x = 0.8;
	fire->pos[5].scale_y = 0.8;
	set_spr(&fire->pos[5], 14.8, 1.4, 0.4);
	create_anim_buff(game, fire->anim, &fire->pos[5].a_buff, 16);
	set_more_fires_2(game, fire);
}

void	set_fires(t_core *game, t_object *fire)
{
	fire->pos[0].volume = 0;
	fire->pos[0].a_tmp = 0;
	fire->pos[0].a_speed = 2;
	fire->pos[0].type = 'f';
	fire->pos[0].scale_x = 1.5;
	fire->pos[0].scale_y = 1.5;
	set_spr(&fire->pos[0], 13.6, 1.4, 0.6);
	create_anim_buff(game, fire->anim, &fire->pos[0].a_buff, 16);
	fire->pos[1].volume = 0;
	fire->pos[1].a_tmp = 0;
	fire->pos[1].a_speed = 2;
	fire->pos[1].type = 'f';
	fire->pos[1].scale_x = 2;
	fire->pos[1].scale_y = 2;
	set_spr(&fire->pos[1], 13.4, 1.6, 0.7);
	create_anim_buff(game, fire->anim, &fire->pos[1].a_buff, 16);
	fire->pos[2].volume = 0;
	fire->pos[2].a_tmp = 0;
	fire->pos[2].a_speed = 1;
	fire->pos[2].type = 'f';
	fire->pos[2].scale_x = 1;
	fire->pos[2].scale_y = 1;
	set_spr(&fire->pos[2], 15.6, 1.6, 0.5);
	create_anim_buff(game, fire->anim, &fire->pos[2].a_buff, 16);
	set_more_fires(game, fire);
}

void	init_fire(t_core *game, char *path)
{
	const int	anim_img_quant = 16;

	if (!(game->fire.anim = (t_tex*)malloc(sizeof(t_tex) * \
		(anim_img_quant + 1))))
		error_malloc(game);
	init_load_anim_images(game, &game->fire, path, anim_img_quant);
	game->fire.quantity = 9;
	if (!(game->fire.pos = (t_sprite*)malloc(sizeof(t_sprite) * \
		game->fire.quantity)))
		error_malloc(game);
	init_a_buff(&game->fire, game->fire.quantity);
	set_fires(game, &game->fire);
}
