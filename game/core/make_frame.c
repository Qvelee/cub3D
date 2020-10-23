/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_frame.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 18:38:23 by nelisabe          #+#    #+#             */
/*   Updated: 2020/10/23 16:44:52 by nelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	void	set_last_sprites(t_core *game, t_list *sprites)
{
	t_sprite	*sprite;

	while (sprites)
	{
		sprite = sprites->content;
		draw_sprite(game, sprite);
		sprites = sprites->next;
	}
}

static	void	z_boofer(t_core *game, t_list *walls, t_list *sprites)
{
	t_ray_cast	*wall;
	t_sprite	*sprite;

	while (walls)
	{
		wall = walls->content;
		sprite = sprites ? sprites->content : NULL;
		if (!sprites || wall->depth >= sprite->depth * \
			cos(game->player.fov / 2 - sprite->ray * game->player.delta_angle))
		{
			if (BONUS)
				set_floor_ceiling(game, wall);
			texture_wall(game, wall);
			walls = walls->next;
		}
		else
		{
			sprites = sprites->next;
			draw_sprite(game, sprite);
		}
	}
	set_last_sprites(game, sprites);
}

void			make_frame(t_core *game)
{
	t_list		*sprites;
	t_list		*walls;
	int			index;

	sprites = NULL;
	walls = NULL;
	index = -1;
	while (game->objects[++index])
	{
		calc_sprites_params(game, game->objects[index]);
		find_visible_sprites(game, game->objects[index], &sprites);
	}
	if (sort_walls(game, &game->buffer, &walls))
		error_newlsts(game, &walls, &sprites);
	z_boofer(game, walls, sprites);
	free_lst(&sprites);
	free_lst(&walls);
}
