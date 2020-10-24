/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pointers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 15:41:39 by nelisabe          #+#    #+#             */
/*   Updated: 2020/10/24 14:21:08 by nelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	init_objects(t_core *game)
{
	game->basic.tex = NULL;
	game->basic.pos = NULL;
	game->basic.anim = NULL;
	game->devil.tex = NULL;
	game->devil.pos = NULL;
	game->devil.anim = NULL;
	game->ghost.tex = NULL;
	game->ghost.pos = NULL;
	game->ghost.anim = NULL;
	game->fire.tex = NULL;
	game->fire.pos = NULL;
	game->fire.anim = NULL;
	game->barrel.tex = NULL;
	game->barrel.pos = NULL;
	game->barrel.anim = NULL;
	game->pedestal.tex = NULL;
	game->pedestal.pos = NULL;
	game->pedestal.anim = NULL;
	game->skull.tex = NULL;
	game->skull.pos = NULL;
	game->skull.anim = NULL;
	game->objects = NULL;
}

static void	init_images(t_core *game)
{
	game->west.img.image = NULL;
	game->north.img.image = NULL;
	game->south.img.image = NULL;
	game->east.img.image = NULL;
	game->wall.img.image = NULL;
	game->wall_dirty.img.image = NULL;
	game->sky.img.image = NULL;
	game->floor.img.image = NULL;
	game->face.img.image = NULL;
}

void		init_pointers(t_core *game)
{
	game->mlx = NULL;
	game->frame.image = NULL;
	game->window = NULL;
	init_images(game);
	init_objects(game);
}
