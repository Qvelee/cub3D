/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 14:00:56 by nelisabe          #+#    #+#             */
/*   Updated: 2020/10/24 14:21:20 by nelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	init_bonus_sprites(t_core *game)
{
	init_fire(game, "./sprites/fire/");
	init_ghost(game, "./sprites/ghost/");
	init_devil(game, "./sprites/devil/");
	init_barrel(game, "./sprites/barrel/");
	init_pedestal(game, "./sprites/pedestal/");
	init_skull(game, "./sprites/skull/");
	if (!(game->objects = (t_object**)malloc(sizeof(t_object*) * 7)))
		error_malloc(game);
	game->objects[0] = &game->devil;
	game->objects[1] = &game->ghost;
	game->objects[2] = &game->fire;
	game->objects[3] = &game->barrel;
	game->objects[4] = &game->pedestal;
	game->objects[5] = &game->skull;
	game->objects[6] = NULL;
}

void		init_sprites(t_core *game)
{
	if (!BONUS)
	{
		init_basic(game, game->params->s);
		if (!(game->objects = (t_object**)malloc(sizeof(t_object*) * 2)))
			error_malloc(game);
		game->objects[0] = &game->basic;
		game->objects[1] = NULL;
	}
	else
		init_bonus_sprites(game);
}
