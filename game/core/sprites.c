/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 12:52:06 by nelisabe          #+#    #+#             */
/*   Updated: 2020/10/06 22:34:28 by nelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_sprite(t_core *game, t_sprite *sprite)
{
	t_tex	texture;

	if (sprite->type == '2')
		texture = game->basic.tex[0];
	sprite->heigth = (int)game->params->r[1] / (sprite->depth / \
		game->map.block_size);
	sprite->width = (int)game->params->r[0] / (sprite->depth /
		game->map.block_size);
	texture.step = texture.height / sprite->heigth;
	texture.step_x = texture.width / sprite->width;

	sprite->ch = sprite->heigth >= game->params->r[1] ? \
		game->params->r[1] - 1 : (int)sprite->heigth;
	sprite->cw = sprite->width >= game->params->r[0] ? \
		game->params->r[0] - 1 : (int)sprite->width;
	//
	texture.x_screen = sprite->ray - sprite->cw / 2;
	if (texture.x_screen < 0)
		texture.x_screen = 0;
	if (texture.x_screen >= game->params->r[0])
		texture.x_screen = game->params->r[0] - 1;
	texture.x_texture = (texture.x_screen - game->params->r[0] / 2 + \
		sprite->width / 2) * texture.step_x;
	while (texture.x_screen < (sprite->ray + sprite->width / 2) &&
		texture.x_screen < game->params->r[0])
	{
		texture.y_screen = game->params->r[1] * sprite->z - sprite->ch / 2;
		texture.y_texture = (texture.y_screen - game->params->r[1] * sprite->z + \
			sprite->heigth / 2) * texture.step;
		while (texture.y_screen < (game->params->r[1] * sprite->z + \
			sprite->heigth / 2) && texture.y_screen < game->params->r[1])
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