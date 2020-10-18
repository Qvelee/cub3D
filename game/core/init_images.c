/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 15:41:39 by nelisabe          #+#    #+#             */
/*   Updated: 2020/10/18 19:22:53 by nelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_objects(t_core *game)
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
	game->objects = NULL;
}

void	init_images(t_core *game)
{
	game->west.img.image = NULL;
	game->north.img.image = NULL;
	game->south.img.image = NULL;
	game->east.img.image = NULL;
	game->sky.img.image = NULL;
	game->floor.img.image = NULL;
	game->face.img.image = NULL;
}
