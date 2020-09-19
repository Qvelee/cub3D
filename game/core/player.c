/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 15:34:34 by nelisabe          #+#    #+#             */
/*   Updated: 2020/09/20 01:06:18 by nelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	int		movement(t_core *game)
{
	if (game->button.left) //left
		game->player.angle -= game->player.angle_speed;
	if (game->button.right) //right
		game->player.angle += game->player.angle_speed;
	if (game->button.a) //a
	{
		game->player.x += game->player.speed * sin(game->player.angle);
		game->player.y += -game->player.speed * cos(game->player.angle);
	}
	if (game->button.w) //w
	{
		game->player.x += game->player.speed * cos(game->player.angle);
		game->player.y += game->player.speed * sin(game->player.angle);
	}
	if (game->button.d) //d
	{
		game->player.x += -game->player.speed * sin(game->player.angle);
		game->player.y += game->player.speed * cos(game->player.angle);
	}
	if (game->button.s) //s
	{		
		game->player.x += -game->player.speed * cos(game->player.angle);
		game->player.y += -game->player.speed * sin(game->player.angle);
	}
	return (0);
}

int				wall_check(t_core *game, double x, double y)
{
	int x_in_map;
	int	y_in_map;

	// printf("x = %f ", x);
	// printf("y = %f\n", y);
	x_in_map = x / game->map.block_size;
	y_in_map = y / game->map.block_size;
	// printf("x = %d ", x_in_map);
	// printf("y = %d\n", y_in_map);
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

static	int		rays(t_core *game)
{
	t_ray_cast	ray;
	int			blocks;
	int			index = 0;
	
	ray.num_rays = game->player.num_rays;
	ray.current_angle = game->player.angle - game->player.fov / 2;
	ray.xm = (int)game->player.x / game->map.block_size * game->map.block_size;
	ray.ym = (int)game->player.y / game->map.block_size * game->map.block_size;
	//printf("xm = %f ym = %f\n", ray.xm, ray.ym);
	while (ray.num_rays--)
	{
		ray.x = cos(ray.current_angle) >= 0 ? \
			ray.xm + game->map.block_size : ray.xm;
		ray.dx = cos(ray.current_angle) >= 0 ? 1.0 : -1.0;
		blocks = game->map.map_colunms;
		while (blocks)
		{
			ray.depth_v = (ray.x - game->player.x) / cos(ray.current_angle);
			ray.y = game->player.y + ray.depth_v * sin(ray.current_angle);
			if (wall_check(game, ray.x + ray.dx, ray.y))
			{
				//ft_putendl_fd("break 1!!!", 1);
				break ;
			}
			ray.x += ray.dx * game->map.block_size;
			blocks--;
		}
		ray.y = sin(ray.current_angle) >= 0 ? \
			ray.ym + game->map.block_size : ray.ym;
		ray.dy = sin(ray.current_angle) >= 0 ? 1.0 : -1.0;
		blocks = game->map.map_lines;
		while (blocks)
		{
			ray.depth_h = (ray.y - game->player.y) / sin(ray.current_angle);
			ray.x = game->player.x + ray.depth_h * cos(ray.current_angle);
			if (wall_check(game, ray.x, ray.y + ray.dy))
			{
				//ft_putendl_fd("break!!!", 1);
				break ;
			}
			ray.y += ray.dy * game->map.block_size;
			blocks--;
		}
		//printf("dv = %f dh = %f\n", ray.depth_v, ray.depth_h);
		ray.depth = ray.depth_v > ray.depth_h ? ray.depth_h : ray.depth_v;
		ray.x = game->player.x + ray.depth * cos(ray.current_angle);
		ray.y = game->player.y + ray.depth * sin(ray.current_angle);
		draw_line(game, game->player.x, game->player.y, ray.x, ray.y);
		ray.current_angle += game->player.delta_angle;
		//printf("--------------------------\n");
	}
	draw_circle(game, game->player.x, game->player.y, 10);
	return (0);
}

void		old_rays(t_core *game)
{
	t_ray_cast	ray;
	
	ray.num_rays = game->player.num_rays;
	ray.current_angle = game->player.angle - game->player.fov / 2;
	while (ray.num_rays--)
	{
		ray.depth = -1;
		while (++ray.depth < game->map.map_colunms * 50)
		{
			ray.x = game->player.x + ray.depth * cos(ray.current_angle);
			ray.y = game->player.y + ray.depth * sin(ray.current_angle);
			draw_line(game, game->player.x, game->player.y, ray.x, ray.y);
			if (wall_check(game, ray.x, ray.y))
			{
				break ;
			}
		}
		ray.current_angle += game->player.delta_angle;
	}
	draw_circle(game, game->player.x, game->player.y, 10);
}

int				player(t_core *game)
{
	movement(game);
	//old_rays(game);
	rays(game);
	return (0);
}