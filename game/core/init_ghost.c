/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ghost.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 18:18:09 by nelisabe          #+#    #+#             */
/*   Updated: 2020/10/21 23:07:59 by nelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_more_ghosts(t_core *game, t_object *ghost)
{
	ghost->pos[3].volume = 0;
	ghost->pos[3].a_tmp = 0;
	ghost->pos[3].a_speed = 2;
	ghost->pos[3].type = 'g';
	ghost->pos[3].scale_x = 1;
	ghost->pos[3].scale_y = 1;
	set_spr(&ghost->pos[3], 4.6, 8.6, 0.5);
	create_anim_buff(game, ghost->anim, &ghost->pos[3].a_buff, 14);
	ghost->pos[4].volume = 0;
	ghost->pos[4].a_tmp = 0;
	ghost->pos[4].a_speed = 5;
	ghost->pos[4].type = 'g';
	ghost->pos[4].scale_x = 0.5;
	ghost->pos[4].scale_y = 0.5;
	set_spr(&ghost->pos[4], 17.6, 10.6, 0.5);
	create_anim_buff(game, ghost->anim, &ghost->pos[4].a_buff, 14);
}

void	set_ghosts(t_core *game, t_object *ghost)
{
	ghost->pos[0].volume = 0;
	ghost->pos[0].a_tmp = 0;
	ghost->pos[0].a_speed = 3;
	ghost->pos[0].type = 'g';
	ghost->pos[0].scale_x = 1;
	ghost->pos[0].scale_y = 1;
	set_spr(&ghost->pos[0], 2.6, 8.6, 0.5);
	create_anim_buff(game, ghost->anim, &ghost->pos[0].a_buff, 14);
	ghost->pos[1].volume = 0;
	ghost->pos[1].a_tmp = 0;
	ghost->pos[1].a_speed = 1;
	ghost->pos[1].type = 'g';
	ghost->pos[1].scale_x = 1.1;
	ghost->pos[1].scale_y = 1.1;
	set_spr(&ghost->pos[1], 3.6, 8.6, 0.5);
	create_anim_buff(game, ghost->anim, &ghost->pos[1].a_buff, 14);
	ghost->pos[2].volume = 0;
	ghost->pos[2].a_tmp = 0;
	ghost->pos[2].a_speed = 2;
	ghost->pos[2].type = 'g';
	ghost->pos[2].scale_x = 1.5;
	ghost->pos[2].scale_y = 1.5;
	set_spr(&ghost->pos[2], 14.5, 11.5, 0.7);
	create_anim_buff(game, ghost->anim, &ghost->pos[2].a_buff, 14);
	set_more_ghosts(game, ghost);
}

void	init_ghost(t_core *game, char *path)
{
	const int	base_img_quant = 1;
	const int	anim_img_quant = 14;

	if (!(game->ghost.tex = (t_tex*)malloc(sizeof(t_tex) * \
		(base_img_quant + 1))))
		error_malloc(game);
	init_load_tex_images(game, &game->ghost, path, base_img_quant);
	if (!(game->ghost.anim = (t_tex*)malloc(sizeof(t_tex) * \
		(anim_img_quant + 1))))
		error_malloc(game);
	init_load_anim_images(game, &game->ghost, path, anim_img_quant);
	game->ghost.quantity = 5;
	if (!(game->ghost.pos = (t_sprite*)malloc(sizeof(t_sprite) * \
		game->ghost.quantity)))
		error_malloc(game);
	init_a_buff(&game->ghost, game->ghost.quantity);
	set_ghosts(game, &game->ghost);
}
