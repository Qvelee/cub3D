/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 14:00:56 by nelisabe          #+#    #+#             */
/*   Updated: 2020/10/15 18:38:28 by nelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//add malloc protect

void	set_spr(t_sprite *sprite, double x, double y, double z)
{
	sprite->x = x;
	sprite->y = y;
	sprite->z = z;
}

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
			ft_lstadd_back(a_buff, tmp);
	}
}

void	init_sprites(t_core *game)
{
	if (!BONUS)
	{
		init_basic(game, game->params->s);
		game->objects = (t_object**)malloc(sizeof(t_object*) * 2);
		game->objects[0] = &game->basic;
		game->objects[1] = NULL;
	}
	else
	{
		init_ghost(game, "./sprites/ghost/");
		init_devil(game, "./sprites/devil/");
		game->objects = (t_object**)malloc(sizeof(t_object*) * 3);
		game->objects[0] = &game->devil;
		game->objects[1] = &game->ghost;
		game->objects[2] = NULL;
	}
}