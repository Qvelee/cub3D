/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_treatment.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 18:26:09 by nelisabe          #+#    #+#             */
/*   Updated: 2020/10/10 19:47:20 by nelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			type_of_sprite(t_core *game, t_sprite *sprite, \
	t_tex *texture, int num)
{
	if (sprite->type == '2')
		*texture = game->basic.tex[num];
	if (sprite->type == 'd')
		*texture = game->devil.tex[num];
}

int				needed_side(t_sprite *sprite)
{
	int		num;
	double	angle;

	num = 0;
	angle = 360;
	if (sprite->condition == 1)
	{
		if (sprite->theta < 22.5 || sprite->theta > 337.5)
			num = 0;
		if (sprite->theta < 67.5 && sprite->theta > 22.5)
			num = 1;
		if (sprite->theta < 112.5 && sprite->theta > 67.5)
			num = 2;
		if (sprite->theta < 157.5 && sprite->theta > 112.5)
			num = 3;
		if (sprite->theta < 202.5 && sprite->theta > 157.5)
			num = 4;
		if (sprite->theta < 247.5 && sprite->theta > 202.5)
			num = 5;
		if (sprite->theta < 292.5 && sprite->theta > 247.5)
			num = 6;
		if (sprite->theta < 337.5 && sprite->theta > 292.5)
			num = 7;
	}
	return (num);
}

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
			object->pos[temp].ray >= game->params->r[0] + width / 2)
			continue ;
		tmplst = ft_lstnew(&object->pos[temp]);
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
