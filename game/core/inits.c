/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 17:52:41 by nelisabe          #+#    #+#             */
/*   Updated: 2020/10/04 20:05:33 by nelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_map(t_core *game)
{
	game->map.x_pos = 0;
	game->map.y_pos = 0;
	game->map.y_scale = game->params->r[1] / 3 / game->map.map_lines;
	game->map.x_scale = game->params->r[0] / 3 / game->map.map_colunms;
	game->map.scale = game->map.y_scale < game->map.x_scale ? \
		game->map.y_scale : game->map.x_scale;
	game->map.sizeX = game->map.scale * game->map.map_colunms;
	game->map.sizeY = game->map.scale * game->map.map_lines;
}

void	init_bonus_images(t_core *game)
{
	game->sky.img.image = mlx_xpm_file_to_image(game->mlx, \
		"./textures/sky3.xpm", &game->sky.width, &game->sky.height);
	game->sky.img.img_addr = mlx_get_data_addr(game->sky.img.image, \
		&game->sky.img.bpp, &game->sky.img.size_line, &game->sky.img.endian);
	game->floor.img.image = mlx_xpm_file_to_image(game->mlx, \
		"./textures/w.xpm", &game->floor.width, &game->floor.height);
	game->floor.img.img_addr = mlx_get_data_addr(game->floor.img.image, \
		&game->floor.img.bpp, &game->floor.img.size_line, \
		&game->floor.img.endian);
	game->face.img.image = mlx_xpm_file_to_image(game->mlx, \
		"./textures/face.xpm", &game->face.width, &game->face.height);
	game->face.img.img_addr = mlx_get_data_addr(game->face.img.image, \
		&game->face.img.bpp, &game->face.img.size_line, \
		&game->face.img.endian);
}

void	init_images(t_core *game)
{
	game->frame.image = mlx_new_image(game->mlx, \
		game->params->r[0], game->params->r[1]);
	game->frame.img_addr = mlx_get_data_addr(game->frame.image, \
		&game->frame.bpp, &game->frame.size_line, \
		&game->frame.endian);
	game->west.img.image = mlx_xpm_file_to_image(game->mlx, \
		game->params->we, &game->west.width, &game->west.height);
	game->west.img.img_addr = mlx_get_data_addr(game->west.img.image, \
		&game->west.img.bpp, &game->west.img.size_line, \
		&game->west.img.endian);
	game->north.img.image = mlx_xpm_file_to_image(game->mlx, \
		game->params->no, &game->north.width, &game->north.height);
	game->north.img.img_addr = mlx_get_data_addr(game->north.img.image, \
		&game->north.img.bpp, &game->north.img.size_line, \
		&game->north.img.endian);
	game->south.img.image = mlx_xpm_file_to_image(game->mlx, \
		game->params->so, &game->south.width, &game->south.height);
	game->south.img.img_addr = mlx_get_data_addr(game->south.img.image, \
		&game->south.img.bpp, &game->south.img.size_line, \
		&game->south.img.endian);
	game->east.img.image = mlx_xpm_file_to_image(game->mlx, \
		game->params->ea, &game->east.width, &game->east.height);
	game->east.img.img_addr = mlx_get_data_addr(game->east.img.image, \
		&game->east.img.bpp, &game->east.img.size_line, \
		&game->east.img.endian);
}
	
void	init_game_settings(t_core *game)
{
	int	temp;

	game->centerX = game->params->r[0] / 2;
	game->centerY = game->params->r[1] / 2;
	game->player.x = 0;
	game->player.y = 0;
	game->map.block_size = 50;
	game->player.angle = 3 * M_PI / 2;
	game->player.speed = game->map.block_size * 0.06;
	game->player.fast_speed = game->player.speed * 2;
	game->player.button_angle_speed = 0.045;
	game->player.mouse_angle_speed = 0.005;
	game->player.radius = game->map.block_size * 0.2;
	game->player.fov = M_PI / 3;
	game->player.num_rays = game->params->r[0]; // 2;
	game->player.delta_angle = game->player.fov / game->player.num_rays;
	game->map.map_lines = -1;
	game->map.map_colunms = 0;
	while (game->params->map[++game->map.map_lines])
		if ((temp = ft_strlen(game->params->map[game->map.map_lines])) > \
			game->map.map_colunms)
			game->map.map_colunms = temp;
	game->frame.image = NULL;
}