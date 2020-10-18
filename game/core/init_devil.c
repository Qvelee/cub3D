/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_devil.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 18:18:03 by nelisabe          #+#    #+#             */
/*   Updated: 2020/10/18 20:20:28 by nelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_devil(t_core *game, char *path)
{
	int			quantity;
	int			temp;

	temp = -1;
	quantity = 8;
	game->devil.tex = (t_tex*)malloc(sizeof(t_tex) * quantity);
	while (++temp < quantity)
		load_image(game, &game->devil.tex[temp], \
			ft_strjoin(path, ft_strjoin(ft_itoa(temp), ".xpm")));
	game->devil.tex[temp].img.image = NULL;
	temp = -1;
	game->devil.anim = (t_tex*)malloc(sizeof(t_tex) * 8);
	while (++temp < 8)
		load_image(game, &game->devil.anim[temp], \
			ft_strjoin(path, ft_strjoin("animation/", \
			ft_strjoin(ft_itoa(temp), ".xpm"))));
	game->devil.anim[8].img.image = NULL;
	game->devil.quantity = 3;
	game->devil.pos = (t_sprite*)malloc(sizeof(t_sprite) * \
		game->devil.quantity);
	game->devil.pos[0].volume = 1;
	game->devil.pos[0].a_tmp = 0;
	game->devil.pos[0].a_speed = 1;
	game->devil.pos[0].condition = 1;
	game->devil.pos[0].type = 'd';
	game->devil.pos[0].scale = 1;
	set_spr(&game->devil.pos[0], 2.5, 1.5, 0.5);
	create_anim_buff(game->devil.anim, &game->devil.pos[0].a_buff, 8);
	game->devil.pos[1].volume = 1;
	game->devil.pos[1].condition = 1;
	game->devil.pos[1].a_tmp = 0;
	game->devil.pos[1].a_speed = 5;
	game->devil.pos[1].type = 'd';
	game->devil.pos[1].scale = 0.3;
	set_spr(&game->devil.pos[1], 6.1, 2.9, 0.5);
	create_anim_buff(game->devil.anim, &game->devil.pos[1].a_buff, 8);
	game->devil.pos[2].volume = 1;
	game->devil.pos[2].condition = 1;
	game->devil.pos[2].a_tmp = 0;
	game->devil.pos[2].a_speed = 5;
	game->devil.pos[2].type = 'd';
	game->devil.pos[2].scale = 1;
	set_spr(&game->devil.pos[2], 13.5, 3.7, 0.5);
	create_anim_buff(game->devil.anim, &game->devil.pos[2].a_buff, 8);
}
