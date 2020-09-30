/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 14:20:51 by nelisabe          #+#    #+#             */
/*   Updated: 2020/09/26 17:29:16 by nelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				wall_check(t_core *game, double x, double y)
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
	
	ray.num_rays = -1;
	ray.current_angle = game->player.angle - game->player.fov / 2;
	set_background(game, &ray);
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