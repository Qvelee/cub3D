/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_skull.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 17:13:57 by nelisabe          #+#    #+#             */
/*   Updated: 2020/10/21 17:54:19 by nelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_skull(t_core *game, t_object *skull)
{
	skull->pos[0].volume = 0;
	skull->pos[0].a_tmp = 0;
	skull->pos[0].a_speed = 25;
	skull->pos[0].type = 's';
	skull->pos[0].scale_x = 1;
	skull->pos[0].scale_y = 1;
	set_spr(&skull->pos[0], 14.9, 1.6, 0.8);
	place_on_map(game, 14.9, 1.6, skull->pos[0].type);
	create_anim_buff(skull->anim, &skull->pos[0].a_buff, 2);
}

void	init_skull(t_core *game, char *path)
{
	int		temp;

	temp = -1;
	if (!(game->skull.anim = (t_tex*)malloc(sizeof(t_tex) * 3)))
		error_malloc(game);
		while (++temp < 2)
			load_image(game, &game->skull.anim[temp], \
				ft_strjoin(path, ft_strjoin("animation/", \
				ft_strjoin(ft_itoa(temp), ".xpm"))));
	game->skull.anim[2].img.image = NULL;
	game->skull.quantity = 1;
	if (!(game->skull.pos = (t_sprite*)malloc(sizeof(t_sprite) * \
		game->skull.quantity)))
		error_malloc(game);
	init_a_buff(&game->skull, game->skull.quantity);
	set_skull(game, &game->skull);
}
