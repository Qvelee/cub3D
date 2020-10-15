/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 19:42:51 by nelisabe          #+#    #+#             */
/*   Updated: 2020/10/15 17:42:23 by nelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	void	tex_pixels(t_core *game, t_tex *texture, t_ray_cast *ray)
{
	texture->proj_copy = (int)ray->wall_height;
	if (texture->proj_copy > game->params->r[1])
		texture->proj_copy = game->params->r[1];
	texture->y_screen = game->params->r[1] / 2 - texture->proj_copy / 2;
	texture->y_texture = (texture->y_screen - game->params->r[1] / 2 + \
		ray->wall_height / 2) * texture->step;
	if (texture->y_texture >= texture->height)
		texture->y_texture = texture->height - 1;
	while (texture->proj_copy)
	{
		game->color = ((int *)(texture->img.img_addr))\
			[(int)texture->y_texture * texture->width + \
			(int)texture->x_texture];
		((int *)(game->frame.img_addr))\
			[(int)texture->y_screen * game->params->r[0] + \
			(int)texture->x_screen] = make_darker(ray->depth, \
			(game->color & 0xFF0000) >> 16, (game->color & 0x00FF00) >> 8, \
			game->color & 0x0000FF);
		texture->y_texture += texture->step;
		texture->y_screen++;
		texture->proj_copy--;
	}
	texture->x_texture++;
	texture->x_screen++;
}

static	void	what_texture(t_core *game, t_ray_cast *ray, t_tex *texture, \
	double temp)
{
	if (!BONUS || BONUS)
	{
		if (temp == ray->xh)
			*texture = object_check(game, ray->x, ray->y + 1, 'W') ? \
				game->north : game->south;
		else
			*texture = object_check(game, ray->x + 1, ray->y, 'W') ? \
				game->west : game->east;
	}
}

void			texture_wall(t_core *game, t_ray_cast *ray)
{
	t_tex	texture;
	double	temp;

	temp = ray->depth_v > ray->depth_h ? ray->xh : ray->yv;
	what_texture(game, ray, &texture, temp);
	texture.offset = temp / game->map.block_size - (int)temp / \
		game->map.block_size;
	if (temp == ray->xh)
		texture.offset = object_check(game, ray->x, ray->y + 1, 'W') ? \
			1 - texture.offset : texture.offset;
	else
		texture.offset = object_check(game, ray->x + 1, ray->y, 'W') ? \
			texture.offset : 1 - texture.offset;
	texture.step = texture.height / ray->wall_height;
	texture.x_screen = ray->num_rays;
	texture.x_texture = texture.offset * (texture.width - 1);
	tex_pixels(game, &texture, ray);
}
