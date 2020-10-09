/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 14:20:51 by nelisabe          #+#    #+#             */
/*   Updated: 2020/10/09 20:50:59 by nelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	void	ray_treatment(t_core *game, t_ray_cast *ray)
{
	if ((ray->depth *= cos(game->player.angle - ray->current_angle)) == 0)
		ray->depth = 0.00001;
	ray->wall_height = (int)game->params->r[1] / \
		(ray->depth / game->map.block_size);
	game->buffer[ray->num_rays].depth_h = ray->depth_h;
	game->buffer[ray->num_rays].depth_v = ray->depth_v;
	game->buffer[ray->num_rays].depth = ray->depth;
	game->buffer[ray->num_rays].x = ray->x;
	game->buffer[ray->num_rays].xh = ray->xh;
	game->buffer[ray->num_rays].y = ray->y;
	game->buffer[ray->num_rays].yv = ray->yv;
	game->buffer[ray->num_rays].wall_height = ray->wall_height;
	game->buffer[ray->num_rays].num_rays = ray->num_rays;
	game->buffer[ray->num_rays].type = ray->type;
}

static	void	verticals(t_core *game, t_ray_cast *ray)
{
	int	blocks;

	ray->x = cos(ray->current_angle) >= 0 ? \
		ray->xm + game->map.block_size : ray->xm;
	ray->dx = cos(ray->current_angle) >= 0 ? 1.0 : -1.0;
	blocks = game->map.map_colunms;
	while (blocks)
	{
		ray->depth_v = (ray->x - game->player.x) / cos(ray->current_angle);
		ray->yv = game->player.y + ray->depth_v * sin(ray->current_angle);
		if (object_check(game, ray->x + ray->dx, ray->yv, 'W'))
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
		if (object_check(game, ray->xh, ray->y + ray->dy, 'W'))
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
	ray.xm = (int)game->player.x / game->map.block_size * game->map.block_size;
	ray.ym = (int)game->player.y / game->map.block_size * game->map.block_size;
	set_sky(game, &ray);
	while (++ray.num_rays < game->player.num_rays)
	{
		ray.type = '1';
		verticals(game, &ray);
		horisontals(game, &ray);
		ray.depth = ray.depth_v > ray.depth_h ? ray.depth_h : ray.depth_v;
		ray.x = game->player.x + ray.depth * cos(ray.current_angle);
		ray.y = game->player.y + ray.depth * sin(ray.current_angle);
		ray_treatment(game, &ray);
		ray.current_angle += game->player.delta_angle;
	}
	return (0);
}
