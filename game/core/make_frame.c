/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_frame.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 18:38:23 by nelisabe          #+#    #+#             */
/*   Updated: 2020/10/07 17:04:37 by nelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//add malloc protect

void	print(void *link)
{
	t_ray_cast *wall;

	wall = link;
	printf("depth -> %f\n", wall->depth);
}

void	add_sprite_to_list(t_list **sprites, t_sprite *sprite, t_list *tmplst)
{
	t_sprite	*temp;
	t_list		*first;
	void		*link;

	first = *sprites;
	if (*sprites)
	{
		while ((*sprites)->next)
		{
			temp = (*sprites)->content;
			if (sprite->depth >= temp->depth)
				break ;
			*sprites = (*sprites)->next;
		}
		tmplst->next = (*sprites)->next;
		link = (*sprites)->content;
		(*sprites)->content = tmplst->content;
		tmplst->content = link;
		(*sprites)->next = tmplst;
		*sprites = first;
	}
	else
		*sprites = tmplst;
}

void	find_visible_sprites(t_core *game, t_object *object, t_list **sprites)
{
	t_list	*tmplst;
	int 	temp;
	
	temp = -1;//object->quantity;
	while (++temp < object->quantity)
	{
		if (object->pos[temp].ray < 0 || object->pos[temp].ray >= game->params->r[0])
			continue ;
		tmplst = ft_lstnew(&object->pos[temp]);
		add_sprite_to_list(sprites, &object->pos[temp], tmplst);
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
		if ((object->pos[temp].dx >= 0 && \
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

void	add_wall_to_list(t_list **walls, t_ray_cast	*wall, t_list *tmplst)
{
	t_ray_cast	*temp;
	t_list		*first;
	void		*link;

	first = *walls;
	if (*walls)
	{
		while ((*walls)->next)
		{
			temp = (*walls)->content;
			if (wall->depth >= temp->depth)
				break ;
			*walls = (*walls)->next;
		}
		tmplst->next = (*walls)->next;
		link = (*walls)->content;
		(*walls)->content = tmplst->content;
		tmplst->content = link;
		(*walls)->next = tmplst;
		*walls = first;
	}
	else
		*walls = tmplst;
}

void	sort_walls(t_core *game, t_ray_cast **buffer, t_list **walls)
{
	t_list	*tmplst;
	int		temp;

	temp = 0;//game->player.num_rays;
	while (temp < game->player.num_rays)
	{
		tmplst = ft_lstnew(&(*buffer)[temp]);
		add_wall_to_list(walls, &(*buffer)[temp], tmplst);
		temp++;
	}
}

void	make_frame(t_core *game)
{
	t_list		*sprites;
	t_list		*walls;
	int			index;	
	t_ray_cast	*wall;
	t_sprite	*sprite;

	static	int	t;
	
	index = -1;
	sprites = NULL;
	walls = NULL;
	calc_sprites_params(game, &game->basic);
	find_visible_sprites(game, &game->basic, &sprites);
	int		temp;

	temp = game->basic.quantity;
	// t_list		*te;
	// te = sprites;
	// while (temp--)
	// {
	// 	if (!sprites)
	// 		break ;
	// 	sprite = sprites->content;
	// 	printf("depth -> %f\n", sprite->depth);
	// 	sprites = sprites->next;
	// }
	// sprites = te;
	printf("%f\n", game->basic.pos[0].dx);
	printf("%f\n", game->basic.pos[0].dy);
	printf("%f\n", game->basic.pos[0].depth);
	printf("%f\n", game->basic.pos[0].theta);
	printf("%f\n", game->basic.pos[0].gamma);
	printf("%f\n", game->basic.pos[0].drays);
	printf("%f\n", game->basic.pos[0].ray);
	sort_walls(game, &game->buffer, &walls);
	// te = walls;
	// temp = game->player.num_rays;
	// while (temp--)
	// {
	// 	if (!walls)
	// 		break ;
	// 	wall = walls->content;
	// 	printf("depth -> %f\n", wall->depth);
	// 	walls = walls->next;
	// }
	// walls = te;
	//ft_lstiter(walls, print);
	while (walls)
	{
		wall = walls->content;
		if (sprites)
			sprite = sprites->content;
		if (!sprites || wall->depth > sprite->depth)
		{
			set_floor_ceiling(game, wall);
			texture_wall(game, wall);
			walls = walls->next;
			//printf("depth -> %f\n", wall->depth);
		}
		else
		{
			sprites = sprites->next;
			//set_sprite(game, sprite);
		}
	}
	// if (!t)
	// 	if (getchar() == 'e')
	// 		t = 1;
	// while (++index < game->player.num_rays)
	// {
	// 	set_floor_ceiling(game, &game->buffer[index]);
	// 	texture_wall(game, &game->buffer[index]);
	// }
	free_lst(&sprites);
	free_lst(&walls);
}