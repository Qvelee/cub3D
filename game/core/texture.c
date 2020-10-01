/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 19:42:51 by nelisabe          #+#    #+#             */
/*   Updated: 2020/09/30 19:42:56 by nelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	void	tex_pixels(t_core *game, t_tex *texture, int scale, double p_height)
{
	while (scale)
	{
		texture->proj_copy = (int)p_height;
		if (texture->proj_copy > game->params->r[1])
			texture->proj_copy = game->params->r[1];
		texture->y_screen = game->params->r[1] / 2 - texture->proj_copy / 2;
		texture->y_texture = (texture->y_screen - game->params->r[1] / 2 + \
			p_height / 2) * texture->step;
		if (texture->y_texture >= texture->height)
			texture->y_texture = texture->height - 1;
		while (texture->proj_copy)
		{
			texture->frame = game->frame.img_addr + \
				((int)texture->y_screen * game->frame.size_line + \
				(int)texture->x_screen * (game->frame.bpp / 8));
			texture->tex_image = texture->img.img_addr + \
				((int)texture->y_texture * texture->img.size_line + \
				(int)texture->x_texture * (texture->img.bpp / 8));
			*(unsigned int*)texture->frame = *(unsigned int*)texture->tex_image;
			texture->y_texture += texture->step;
			texture->y_screen++;
			texture->proj_copy--;
		}
		texture->x_texture++;
		texture->x_screen++;
		scale--;
	}
}

void			texture(t_core *game, t_ray_cast *ray, int scale, double p_height)
{
	t_tex	texture;
	double	temp;

	temp = ray->depth_v > ray->depth_h ? ray->xh : ray->yv;
	if (temp == ray->xh)
		texture = wall_check(game, ray->x, ray->y + 1) ? game->west : game->east;
	else
		texture = wall_check(game, ray->x + 1, ray->y) ? game->south : game->north;
	texture.offset = temp / game->map.block_size - (int)temp / game->map.block_size;
	texture.step = texture.height / p_height;
	texture.x_screen = ray->num_rays * scale;
	texture.x_texture = texture.offset * (texture.width - 1);
	tex_pixels(game, &texture, scale, p_height);
}
