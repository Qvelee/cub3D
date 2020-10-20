/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_treatment.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 18:26:09 by nelisabe          #+#    #+#             */
/*   Updated: 2020/10/20 22:07:40 by nelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	void	add_sprite_to_list(t_list **sprites, t_sprite *sprite, \
	t_list *tmplst)
{
	t_sprite		*temp;
	const t_list	*first = *sprites;
	void			*link;

	while ((*sprites))
	{
		temp = (*sprites)->content;
		if (sprite->depth >= temp->depth)
		{
			tmplst->next = (*sprites)->next;
			link = (*sprites)->content;
			(*sprites)->content = tmplst->content;
			tmplst->content = link;
			(*sprites)->next = tmplst;
			break ;
		}
		if (!(*sprites)->next)
		{
			ft_lstadd_back(sprites, tmplst);
			break ;
		}
		*sprites = (*sprites)->next;
	}
	*sprites = *sprites ? (t_list*)first : tmplst;
}

void			find_visible_sprites(t_core *game, t_object *object, \
	t_list **sprites)
{
	t_list	*tmplst;
	int		width;
	int		temp;

	temp = -1;
	while (++temp < object->quantity)
	{
		width = (int)game->params->r[1] / (object->pos[temp].depth /
			game->map.block_size) * object->pos[temp].scale;
		if (object->pos[temp].ray < -1 * width / 2 || \
			object->pos[temp].ray >= game->params->r[0] + width / 2 || \
			object->pos[temp].depth <= 1)
			continue ;
		if (!(tmplst = ft_lstnew(&object->pos[temp])))
			error_newlst(game, sprites);
		add_sprite_to_list(sprites, &object->pos[temp], tmplst);
	}
}

void			calc_sprites_params(t_core *game, t_object *object)
{
	int temp;

	temp = object->quantity;
	while (temp--)
	{
		object->pos[temp].dx = object->pos[temp].x * game->map.block_size - \
			game->player.x;
		object->pos[temp].dy = object->pos[temp].y * game->map.block_size - \
			game->player.y;
		object->pos[temp].depth = sqrt(powf(object->pos[temp].dx, 2) + \
			powf(object->pos[temp].dy, 2));
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
	}
}
