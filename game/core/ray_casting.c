/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 14:20:51 by nelisabe          #+#    #+#             */
/*   Updated: 2020/09/23 17:40:37 by nelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	int		wall_check(t_core *game, double x, double y)
{
	int x_in_map;
	int	y_in_map;

	x_in_map = x / game->map.block_size;
	y_in_map = y / game->map.block_size;
	if (y_in_map > game->map.map_lines - 1 || \
		x_in_map > game->map.map_colunms - 1)
		return (1);
	if (y_in_map < 0 || x_in_map < 0)
		return (1);	
	if (game->params->map[y_in_map][x_in_map] == '1' || \
		game->params->map[y_in_map][x_in_map] == '\0')
		return (1);
	return (0);
}

void			texture(t_core *game, t_ray_cast *ray, int scale, double proj_height)
{
	double	step;
	double	x_screen;
	double	y_screen;
	double	x_texture;
	double	y_texture;
	t_textures	texture;

	ray->offset = ray->depth_v > ray->depth_h ? ray->xh : ray->yv;
	texture = ray->depth_v > ray->depth_h ? game->south : game->east;
	ray->offset = ray->offset / game->map.block_size;
	while (ray->offset > 1)
		ray->offset--;
	step = texture.height / proj_height;
	x_screen = ray->num_rays * scale;
	x_texture = ray->offset * (texture.width - 1);
	int		proj_copy = proj_height;
	char	*dst;
	char	*tex;
	while (scale)
	{
		proj_copy = (int)proj_height;
		if (proj_copy > game->params->r[1])
			proj_copy = game->params->r[1];
		y_screen = game->params->r[1] / 2 - proj_copy / 2;
		y_texture = (y_screen - game->params->r[1] / 2 + proj_height / 2) * step;
		if (y_texture >= texture.height)
			y_texture = texture.height - 1;
		while (proj_copy)
		{
			dst = game->frame.img_addr + ((int)y_screen * game->frame.size_line + \
				(int)x_screen * (game->frame.bpp / 8));
			tex = texture.img.img_addr + ((int)y_texture * texture.img.size_line + \
				(int)x_texture * (texture.img.bpp / 8));
			// *(unsigned int*)dst = rgb_to_num(ray, *(unsigned int*)tex >> 16, \
			// *(unsigned int*)tex >> 8, *(unsigned int*)tex);
			//*(unsigned int*)dst = *(unsigned int*)tex / (1 + ray->depth * ray->depth * 0.00001);
			*(unsigned int*)dst = *(unsigned int*)tex;
			y_texture += step;
			y_screen++;
			proj_copy--;
		}
		x_texture++;
		x_screen++;
		scale--;
	}
}

static	void	ray_to_rectangle(t_core *game, t_ray_cast *ray)
{
	double	dist;
	double	coef;
	int		scale;
	double	proj_height;

	dist = game->player.num_rays / (2 * tan(game->player.fov / 2));
	coef = dist * game->map.block_size;
	scale = game->params->r[0] / game->player.num_rays;
	if ((ray->depth *= cos(game->player.angle - ray->current_angle)) == 0)
		ray->depth = 0.00001;
	proj_height = coef / ray->depth;
	game->color = rgb_to_num(ray, 250, 250, 250);
	// if (proj_height > game->params->r[1])
	// 	proj_height = game->params->r[1];
	// draw_rect(game, ray->num_rays * scale, \
	// 	game->params->r[1] / 2 - proj_height / 2, scale, proj_height);
	texture(game, ray, scale, proj_height);
}

static	void	verticals(t_core *game, t_ray_cast *ray)
{
	int blocks;

	ray->x = cos(ray->current_angle) >= 0 ? \
			ray->xm + game->map.block_size : ray->xm;
	ray->dx = cos(ray->current_angle) >= 0 ? 1.0 : -1.0;
	blocks = game->map.map_colunms;
	while (blocks)
	{
		ray->depth_v = (ray->x - game->player.x) / cos(ray->current_angle);
		ray->yv = game->player.y + ray->depth_v * sin(ray->current_angle);
		if (wall_check(game, ray->x + ray->dx, ray->yv))
			break ;
		ray->x += ray->dx * game->map.block_size;
		blocks--;
	}
}

static	void	horisontals(t_core *game, t_ray_cast *ray)
{
	int	blocks;

	ray->y = sin(ray->current_angle) >= 0 ? \
		ray->ym + game->map.block_size : ray->ym;
	ray->dy = sin(ray->current_angle) >= 0 ? 1.0 : -1.0;
	blocks = game->map.map_lines;
	while (blocks)
	{
		ray->depth_h = (ray->y - game->player.y) / sin(ray->current_angle);
		ray->xh = game->player.x + ray->depth_h * cos(ray->current_angle);
		if (wall_check(game, ray->xh, ray->y + ray->dy))
			break ;
		ray->y += ray->dy * game->map.block_size;
		blocks--;
	}
}

int				ray_casting(t_core *game)
{
	t_ray_cast	ray;
	
	game->color = 0x66CCFF;
	draw_rect(game, 0, 0, game->params->r[0], \
		game->params->r[1] / 2);
	game->color = 0xBBBBBB;
	draw_rect(game, 0, game->params->r[1] / 2, \
		game->params->r[0], game->params->r[1] / 2);
	ray.num_rays = -1;
	ray.current_angle = game->player.angle - game->player.fov / 2;
	ray.xm = (int)game->player.x / game->map.block_size * game->map.block_size;
	ray.ym = (int)game->player.y / game->map.block_size * game->map.block_size;
	while (++ray.num_rays < game->player.num_rays)
	{
		verticals(game, &ray);
		horisontals(game, &ray);
		ray.depth = ray.depth_v > ray.depth_h ? ray.depth_h : ray.depth_v;
		ray.x = game->player.x + ray.depth * cos(ray.current_angle);
		ray.y = game->player.y + ray.depth * sin(ray.current_angle);
		ray_to_rectangle(game, &ray);
		ray.current_angle += game->player.delta_angle;
	}
	return (0);
}