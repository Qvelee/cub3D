/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_devil.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 18:18:03 by nelisabe          #+#    #+#             */
/*   Updated: 2020/10/20 22:50:26 by nelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_more_devils(t_core *game, t_object *devil)
{
	devil->pos[3].volume = 1;
	devil->pos[3].a_tmp = 0;
	devil->pos[3].a_speed = 2;
	devil->pos[3].type = 'd';
	devil->pos[3].scale = 1;
	set_spr(&devil->pos[3], 6.6, 2.6, 0.5);
	place_on_map(game, 6.6, 2.6, devil->pos[3].type);
	create_anim_buff(devil->anim, &devil->pos[3].a_buff, 14);
	devil->pos[4].volume = 1;
	devil->pos[4].a_tmp = 0;
	devil->pos[4].a_speed = 2;
	devil->pos[4].type = 'd';
	devil->pos[4].scale = 0.7;
	set_spr(&devil->pos[4], 9.6, 2.6, 0.5);
	place_on_map(game, 9.6, 2.6, devil->pos[4].type);
	create_anim_buff(devil->anim, &devil->pos[4].a_buff, 14);
	devil->pos[5].volume = 1;
	devil->pos[5].a_tmp = 0;
	devil->pos[5].a_speed = 2;
	devil->pos[5].type = 'd';
	devil->pos[5].scale = 0.5;
	set_spr(&devil->pos[5], 7.6, 2.6, 0.5);
	place_on_map(game, 7.6, 2.6, devil->pos[5].type);
	create_anim_buff(devil->anim, &devil->pos[5].a_buff, 14);
}

void	set_devils(t_core *game, t_object *devil)
{
	devil->pos[0].volume = 1;
	devil->pos[0].a_tmp = 0;
	devil->pos[0].a_speed = 3;
	devil->pos[0].type = 'd';
	devil->pos[0].scale = 1;
	set_spr(&devil->pos[0], 9.6, 1.6, 0.5);
	place_on_map(game, 9.6, 1.6, devil->pos[0].type);
	create_anim_buff(devil->anim, &devil->pos[0].a_buff, 14);
	devil->pos[1].volume = 1;
	devil->pos[1].a_tmp = 0;
	devil->pos[1].a_speed = 1;
	devil->pos[1].type = 'd';
	devil->pos[1].scale = 1.1;
	set_spr(&devil->pos[1], 8.6, 1.6, 0.5);
	place_on_map(game, 8.6, 1.6, devil->pos[1].type);
	create_anim_buff(devil->anim, &devil->pos[1].a_buff, 14);
	devil->pos[2].volume = 1;
	devil->pos[2].a_tmp = 0;
	devil->pos[2].a_speed = 2;
	devil->pos[2].type = 'd';
	devil->pos[2].scale = 1;
	set_spr(&devil->pos[2], 6.6, 1.6, 0.5);
	place_on_map(game, 6.6, 1.6, devil->pos[2].type);
	create_anim_buff(devil->anim, &devil->pos[2].a_buff, 14);
	set_more_devils(game, devil);
}

void	init_devil(t_core *game, char *path)
{
	int			quantity;
	int			temp;

	temp = -1;
	quantity = 8;
	if (!(game->devil.tex = (t_tex*)malloc(sizeof(t_tex) * (quantity + 1))))
		error_malloc(game);
	while (++temp < quantity)
		load_image(game, &game->devil.tex[temp], \
			ft_strjoin(path, ft_strjoin(ft_itoa(temp), ".xpm")));
	game->devil.tex[temp].img.image = NULL;
	temp = -1;
	if (!(game->devil.anim = (t_tex*)malloc(sizeof(t_tex) * 15)))
		error_malloc(game);
	while (++temp < 14)
		load_image(game, &game->devil.anim[temp], \
			ft_strjoin(path, ft_strjoin("animation/", \
			ft_strjoin(ft_itoa(temp), ".xpm"))));
	game->devil.anim[14].img.image = NULL;
	game->devil.quantity = 6;
	if (!(game->devil.pos = (t_sprite*)malloc(sizeof(t_sprite) * \
		game->devil.quantity)))
		error_malloc(game);
	init_a_buff(&game->devil, game->devil.quantity);
	set_devils(game, &game->devil);
}
