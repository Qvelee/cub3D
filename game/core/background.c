/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 16:59:26 by nelisabe          #+#    #+#             */
/*   Updated: 2020/10/10 20:01:25 by nelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	void	tex_pixels(t_core *game, t_tex *texture, t_flr_ceil *fc)
{
	while (++texture->y_screen < game->params->r[1])
	{
		fc->screen_dist = game->params->r[1] / \
			(2.0 * (int)texture->y_screen - game->params->r[1]);
		fc->weight = fc->screen_dist / fc->dist_to_wall;
		fc->screen_floor_x = fc->weight * fc->floor_x + \
			(1.0 - fc->weight) * game->player.x / game->map.block_size;
		fc->screen_floor_y = fc->weight * fc->floor_y + \
			(1.0 - fc->weight) * game->player.y / game->map.block_size;
		fc->screen_floor_x -= (int)fc->screen_floor_x;
		texture->x_texture = fc->screen_floor_x * texture->width;
		fc->screen_floor_y -= (int)fc->screen_floor_y;
		texture->y_texture = fc->screen_floor_y * texture->height;
		game->color = ((int *)(texture->img.img_addr))\
		[(int)texture->y_texture * texture->width + (int)texture->x_texture];
		((int *)(game->frame.img_addr))\
			[(int)texture->y_screen * game->params->r[0] + \
			(int)texture->x_screen] = make_darker(fc->screen_dist * \
			game->map.block_size, (game->color & 0xFF0000) >> 16, \
			(game->color & 0x00FF00) >> 8, game->color & 0x0000FF);
	}
}

void			set_floor_ceiling(t_core *game, t_ray_cast *ray)
{
	t_tex		texture;
	t_flr_ceil	fc;

	texture = game->floor;
	fc.floor_x = ray->x / game->map.block_size;
	fc.floor_y = ray->y / game->map.block_size;
	texture.x_screen = ray->num_rays;
	fc.dist_to_wall = ray->depth / game->map.block_size;
	fc.lineheight = (int)(game->params->r[1] / fc.dist_to_wall) - 1;
	if ((texture.y_screen = fc.lineheight / 2 + game->params->r[1] / 2) >= \
		game->params->r[1])
		texture.y_screen = game->params->r[1] - 1;
	if (texture.y_screen < 0)
		texture.y_screen = game->params->r[1];
	tex_pixels(game, &texture, &fc);
}

void			set_sky(t_core *game, t_ray_cast *ray)
{
	t_tex	texture;

	texture = game->sky;
	texture.step = game->sky.height / (game->params->r[1] / 2);
	texture.offset = (game->player.angle) * 180 / M_PI / 360 * 5;
	if (texture.offset >= 1)
		texture.offset = texture.offset - (int)texture.offset;
	texture.x_screen = -1;
	texture.x_texture = texture.offset * texture.width;
	texture.x_texture = texture.x_texture < 0 ? texture.width - 1 + \
		texture.x_texture : texture.x_texture;
	while (++texture.x_screen < game->params->r[0])
	{
		texture.y_screen = -1;
		texture.y_texture = 0;
		while (++texture.y_screen < game->params->r[1] / 2)
		{
			((int *)(game->frame.img_addr))\
				[(int)texture.y_screen * game->params->r[0] + \
				(int)texture.x_screen] = ((int *)(texture.img.img_addr))\
				[(int)texture.y_texture * texture.width + \
				(int)texture.x_texture];
			texture.y_texture += texture.step;
		}
		texture.x_texture = texture.x_texture < texture.width - 1 ? \
			texture.x_texture + 1 : 0;
	}
}
