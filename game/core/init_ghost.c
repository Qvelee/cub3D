/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ghost.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 18:18:09 by nelisabe          #+#    #+#             */
/*   Updated: 2020/10/15 18:34:41 by nelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_ghost(t_core *game, char *path)
{
	int		quantity;
 	int		temp;

	quantity = 1;
	temp = -1;
	game->ghost.tex = (t_tex*)malloc(sizeof(t_tex) * quantity);
	while (++temp < quantity)
		load_image(game, &game->ghost.tex[temp], \
			ft_strjoin(path, ft_strjoin(ft_itoa(temp), ".xpm")));
	temp = -1;
	game->ghost.anim = (t_tex*)malloc(sizeof(t_tex) * 8);
	while (++temp < 8)
		load_image(game, &game->ghost.anim[temp], \
			ft_strjoin(path, ft_strjoin("animation/", \
			ft_strjoin(ft_itoa(temp), ".xpm"))));
	game->ghost.quantity = 1;
	game->ghost.pos = (t_sprite*)malloc(sizeof(t_sprite) * \
		game->ghost.quantity);
	game->ghost.pos[0].condition = 1;
	game->ghost.pos[0].volume = 0;
	game->ghost.pos[0].a_tmp = 0;
	game->ghost.pos[0].a_speed = 5;
	game->ghost.pos[0].type = 'p';
	game->ghost.pos[0].scale = 1;
	set_spr(&game->ghost.pos[0], 7.5, 3.5, 0.5);
	create_anim_buff(game->ghost.anim, &game->ghost.pos[0].a_buff, 8);
}
