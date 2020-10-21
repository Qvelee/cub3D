/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 14:00:56 by nelisabe          #+#    #+#             */
/*   Updated: 2020/10/21 17:17:23 by nelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//add malloc protect

void	create_anim_buff(t_tex *anim, t_list **a_buff, int quant)
{
	t_list	*tmp;
	t_list	*last;
	int		temp;

	temp = -1;
	while (++temp < quant)
	{
		tmp = ft_lstnew(&anim[temp]);
		if (temp == quant - 1)
		{
			tmp->next = *a_buff;
			last = ft_lstlast(*a_buff);
			last->next = tmp;
		}
		else
		{
			ft_lstadd_back(a_buff, tmp);
		}
	}
}

void	init_a_buff(t_object *sprite, int quant)
{
	int index;

	index = -1;
	while (++index < quant)
		sprite->pos[index].a_buff = NULL;
}

void	init_sprites(t_core *game)
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
}