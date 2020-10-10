/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 12:52:06 by nelisabe          #+#    #+#             */
/*   Updated: 2020/10/10 20:08:55 by nelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	void	calc_properties(t_core *game, t_sprite *sprite, t_tex *texture)
{
	if (sprite->theta < 0)
		sprite->theta += 2 * M_PI;
	sprite->theta = 360 - sprite->theta * 180 / M_PI;
	type_of_sprite(game, sprite, texture, needed_side(sprite));
	sprite->heigth = (int)game->params->r[1] / (sprite->depth / \
		game->map.block_size) * sprite->scale;
	sprite->width = (int)game->params->r[1] / (sprite->depth /
		game->map.block_size) * sprite->scale;
	texture->step = texture->height / sprite->heigth;
	texture->step_x = texture->width / sprite->width;
	sprite->ch = sprite->heigth >= game->params->r[1] ? \
		game->params->r[1] - 1 : (int)sprite->heigth;
	sprite->cw = sprite->width >= game->params->r[0] ? \
		game->params->r[0] - 1 : (int)sprite->width;
	texture->x_screen = sprite->ray - sprite->cw / 2;
	texture->x_texture = 0;
	if (texture->x_screen < 0)
	{
		texture->x_texture += -1 * texture->x_screen * texture->step_x;
		texture->x_screen = 0;
	}
}

void			draw_sprite(t_core *game, t_sprite *sprite)
{
	t_tex	texture;
	double	ccw;
	double	cch;

	calc_properties(game, sprite, &texture);
	ccw = sprite->cw;
	while (ccw-- && texture.x_texture < texture.width \
		&& texture.x_screen < game->params->r[0])
	{
		cch = sprite->ch;
		texture.y_screen = game->params->r[1] * sprite->z - sprite->ch / 2;
		texture.y_texture = (texture.y_screen - game->params->r[1] * \
			sprite->z + sprite->heigth / 2) * texture.step;
		while (cch--)
		{
			set_pixel(game, &texture, sprite->depth);
			texture.y_screen++;
			texture.y_texture += texture.step;
		}
		texture.x_screen++;
		texture.x_texture += texture.step_x;
	}
}
