/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fire.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 18:34:55 by nelisabe          #+#    #+#             */
/*   Updated: 2020/10/20 22:48:09 by nelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_more_fires(t_core *game, t_object *fire)
{
	fire->pos[3].volume = 0;
	fire->pos[3].a_tmp = 0;
	fire->pos[3].a_speed = 2;
	fire->pos[3].type = 'f';
	fire->pos[3].scale = 1;
	set_spr(&fire->pos[3], 15.6, 7.6, 0.5);
	place_on_map(game, 15.6, 7.6, fire->pos[3].type);
	create_anim_buff(fire->anim, &fire->pos[3].a_buff, 16);
	fire->pos[4].volume = 0;
	fire->pos[4].a_tmp = 0;
	fire->pos[4].a_speed = 2;
	fire->pos[4].type = 'f';
	fire->pos[4].scale = 1;
	set_spr(&fire->pos[4], 15.6, 8.6, 0.5);
	place_on_map(game, 15.6, 8.6, fire->pos[4].type);
	create_anim_buff(fire->anim, &fire->pos[4].a_buff, 16);
	// fire->pos[5].volume = 0;
	// fire->pos[5].a_tmp = 0;
	// fire->pos[5].a_speed = 2;
	// fire->pos[5].type = 'f';
	// fire->pos[5].scale = 1;
	// set_spr(&fire->pos[5], 15.6, 9.6, 0.5);
	// place_on_map(game, 15.6, 9.6, fire->pos[5].type);
	// create_anim_buff(fire->anim, &fire->pos[5].a_buff, 16);
}

void	set_fires(t_core *game, t_object *fire)
{
	fire->pos[0].volume = 0;
	fire->pos[0].a_tmp = 0;
	fire->pos[0].a_speed = 3;
	fire->pos[0].type = 'f';
	fire->pos[0].scale = 1;
	set_spr(&fire->pos[0], 16.6, 7.6, 0.5);
	place_on_map(game, 16.6, 7.6, fire->pos[0].type);
	create_anim_buff(fire->anim, &fire->pos[0].a_buff, 16);
	fire->pos[1].volume = 0;
	fire->pos[1].a_tmp = 0;
	fire->pos[1].a_speed = 1;
	fire->pos[1].type = 'f';
	fire->pos[1].scale = 1;
	set_spr(&fire->pos[1], 16.6, 8.6, 0.5);
	place_on_map(game, 16.6, 8.6, fire->pos[1].type);
	create_anim_buff(fire->anim, &fire->pos[1].a_buff, 16);
	fire->pos[2].volume = 0;
	fire->pos[2].a_tmp = 0;
	fire->pos[2].a_speed = 2;
	fire->pos[2].type = 'f';
	fire->pos[2].scale = 1;
	set_spr(&fire->pos[2], 16.6, 9.6, 0.5);
	place_on_map(game, 16.6, 9.6, fire->pos[2].type);
	create_anim_buff(fire->anim, &fire->pos[2].a_buff, 16);
	set_more_fires(game, fire);
}

void	init_fire(t_core *game, char *path)
{
	int			quantity;
	int			temp;

	temp = -1;
	quantity = 1;
	if (!(game->fire.tex = (t_tex*)malloc(sizeof(t_tex) * (quantity + 1))))
		error_malloc(game);
	while (++temp < quantity)
		load_image(game, &game->fire.tex[temp], \
			ft_strjoin(path, ft_strjoin(ft_itoa(temp), ".xpm")));
	game->fire.tex[temp].img.image = NULL;
	temp = -1;
	if (!(game->fire.anim = (t_tex*)malloc(sizeof(t_tex) * 17)))
		error_malloc(game);
	while (++temp < 16)
		load_image(game, &game->fire.anim[temp], \
			ft_strjoin(path, ft_strjoin("animation/", \
			ft_strjoin(ft_itoa(temp), ".xpm"))));
	game->fire.anim[16].img.image = NULL;
	game->fire.quantity = 5;
	if (!(game->fire.pos = (t_sprite*)malloc(sizeof(t_sprite) * \
		game->fire.quantity)))
		error_malloc(game);
	init_a_buff(&game->fire, game->fire.quantity);
	set_fires(game, &game->fire);
}
