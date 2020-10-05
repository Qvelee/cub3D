/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_frame.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 18:38:23 by nelisabe          #+#    #+#             */
/*   Updated: 2020/10/06 00:55:04 by nelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//add malloc protect

void	add_to_list(t_list **sprites, t_sprite *sprite, t_list *tmplst)
{
	t_sprite	*temp;
	t_list		*first;

	first = *sprites;
	// printf("ray-> %f\n", sprite->ray);
	if (*sprites)
	{
		temp = (*sprites)->content;
		while (sprite->depth > temp->depth)
		{
			*sprites = (*sprites)->next;
			temp = (*sprites)->content;
		}
		tmplst->next = (*sprites)->next;
		(*sprites)->next = tmplst;
		(*sprites) = first;
	}
	else
	{
		//printf("lol\n");
		*sprites = tmplst;
	}
}

void	find_visible_sprites(t_core *game, t_object *object, t_list **sprites)
{
	t_list	*tmplst;
	int 	temp;
	
	temp = object->quantity;
	while (temp--)
	{
		if (object->pos[temp].ray < 0 || object->pos[temp].ray >= game->params->r[0])
			continue ;
		tmplst = ft_lstnew(&object->pos[temp]);
		//printf("que?\n");
		add_to_list(sprites, &object->pos[temp], tmplst);
		//printf("que wa?\n");
	}
}

void	calc_sprites_params(t_core *game, t_object *object)
{
	int temp;

	temp = object->quantity;
	while (temp--)
	{
		object->pos[temp].dx = object->pos[temp].x * game->map.block_size - \
			game->player.x;
		object->pos[temp].dy = object->pos[temp].y * game->map.block_size - \
			game->player.y;
		object->pos[temp].depth = sqrt\
			(powf(object->pos[temp].dx, 2) + powf(object->pos[temp].dy, 2));
		object->pos[temp].theta = atan2(object->pos[temp].dy, \
			object->pos[temp].dx);
		object->pos[temp].gamma = object->pos[temp].theta - game->player.angle;
		if ((object->pos[temp].dx > 0 && \
			180 <= game->player.angle * 180 / M_PI && \
			360 >= game->player.angle * 180 / M_PI) || \
			(object->pos[temp].dx < 0 && object->pos[temp].dy < 0))
			object->pos[temp].gamma += 2 * M_PI;
		object->pos[temp].drays = \
			object->pos[temp].gamma / game->player.delta_angle;
		object->pos[temp].ray = (game->params->r[0] / 2 - 1)\
			+ object->pos[temp].drays;
		if ((object->pos[temp].depth *= cos(game->player.fov / 2 - \
			object->pos[temp].ray * game->player.delta_angle)) == 0)
			object->pos[temp].depth = 0.00001;
	}
}

void	print(void *link)
{
	t_sprite *sprite;
	
	sprite = link;
	printf("depth -> %f\n", sprite->depth);
}

void	make_frame(t_core *game)
{
	t_list	*sprites;
	int		index;
	
	index = -1;
	sprites = NULL;
	calc_sprites_params(game, &game->basic);
	find_visible_sprites(game, &game->basic, &sprites);
	//printf("size -> %d\n", ft_lstsize(sprites));
	//ft_lstiter(sprites, print);
	if (sprites)
		ft_lstclear(&sprites, free);
	// printf("dx = %f\ndy = %f\n", game->basic.pos[0].dx, game->basic.pos[0].dy);
	// printf("depth -> %f\n", game->basic.pos[0].depth);
	// printf("dray = %f\n", game->basic.pos[0].drays);
	// printf("x = %f\ny = %f\nray = %f\ntheta = %f\ngamma = %f\n", \
	// 	game->basic.pos[0].x, game->basic.pos[0].y, \
	// 	game->basic.pos[0].ray, game->basic.pos[0].theta * 180 / M_PI, \
	// 	game->basic.pos[0].gamma * 180 / M_PI);
	while (++index < game->player.num_rays)
	{
		set_floor_ceiling(game, &game->buffer[index]);
		texture_wall(game, &game->buffer[index]);
	}
}