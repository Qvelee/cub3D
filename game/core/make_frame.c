/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_frame.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 18:38:23 by nelisabe          #+#    #+#             */
/*   Updated: 2020/10/09 20:08:12 by nelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//add malloc protect

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

	temp = 0;
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
	
	sprites = NULL;
	walls = NULL;
	calc_sprites_params(game, &game->basic);
	find_visible_sprites(game, &game->basic, &sprites);
	sort_walls(game, &game->buffer, &walls);
	while (walls)
	{
		wall = walls->content;
		if (sprites)
			sprite = sprites->content;
		if (!sprites || wall->depth >= sprite->depth * cos(game->player.fov / 2 - \
		 	sprite->ray * game->player.delta_angle))
		{
			set_floor_ceiling(game, wall);
			texture_wall(game, wall);
			walls = walls->next;
		}
		else
		{
			sprites = sprites->next;
			set_sprite(game, sprite);
		}
	}
	while (sprites)
	{
		sprite = sprites->content;
		set_sprite(game, sprite);
		sprites = sprites->next;
	}
	free_lst(&sprites);
	free_lst(&walls);
}