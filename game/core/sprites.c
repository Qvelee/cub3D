/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 12:52:06 by nelisabe          #+#    #+#             */
/*   Updated: 2020/10/09 21:53:27 by nelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	}
}

void	add_sprite_to_list(t_list **sprites, t_sprite *sprite, t_list *tmplst)
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

void	find_visible_sprites(t_core *game, t_object *object, t_list **sprites)
{
	t_list	*tmplst;
	int		width;
	int 	temp;
	
	temp = -1;
	while (++temp < object->quantity)
	{
		width = (int)game->params->r[1] / (object->pos[temp].depth /
			game->map.block_size);
		if (object->pos[temp].ray < -1 * width / 2 || \
			object->pos[temp].ray >= game->params->r[0] + width / 2)
			continue ;
		tmplst = ft_lstnew(&object->pos[temp]);
		add_sprite_to_list(sprites, &object->pos[temp], tmplst);
	}
}

void	set_sprite(t_core *game, t_sprite *sprite)
{
	t_tex	texture;

	if (sprite->theta < 0)
		sprite->theta += 2 * M_PI;
	sprite->theta = 360 - sprite->theta * 180 / M_PI;
	if (sprite->type == '2')
	{
		double	angle = 360;
		int		num;
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
		texture = game->basic.tex[num];
	}
	sprite->heigth = (int)game->params->r[1] / (sprite->depth / \
		game->map.block_size);
	sprite->width = (int)game->params->r[1] / (sprite->depth /
		game->map.block_size);
	texture.step = texture.height / sprite->heigth;
	texture.step_x = texture.width / sprite->width;
	sprite->ch = sprite->heigth >= game->params->r[1] ? \
		game->params->r[1] - 1 : (int)sprite->heigth;
	sprite->cw = sprite->width >= game->params->r[0] ? \
		game->params->r[0] - 1 : (int)sprite->width;
	texture.x_screen = sprite->ray - sprite->cw / 2;
	texture.x_texture = 0;
	if (texture.x_screen < 0)
	{
		texture.x_texture += -1 * texture.x_screen * texture.step_x;
		texture.x_screen = 0;
	}
	double ccw;
	double cch;

	ccw = sprite->cw;
	while (ccw-- && texture.x_texture < texture.width \
		&& texture.x_screen < game->params->r[0])
	{
		cch = sprite->ch;
		texture.y_screen = game->params->r[1] * sprite->z - sprite->ch / 2;
		texture.y_texture = (texture.y_screen - game->params->r[1] * sprite->z + \
			sprite->heigth / 2) * texture.step;
		while (cch--)
		{
			game->color = ((int *)(texture.img.img_addr))\
			[(int)texture.y_texture * texture.width + \
			(int)texture.x_texture];
			if (game->color != 0)
				((int *)(game->frame.img_addr))\
					[(int)texture.y_screen * game->params->r[0] + \
					(int)texture.x_screen] = make_darker(sprite->depth, \
					(game->color & 0xFF0000) >> 16, (game->color & 0x00FF00) >> 8, \
					game->color & 0x0000FF);
			texture.y_screen++;
			texture.y_texture += texture.step;
		}
		texture.x_screen++;		
		texture.x_texture += texture.step_x;
	}
}