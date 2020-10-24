/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 17:52:41 by nelisabe          #+#    #+#             */
/*   Updated: 2020/10/24 14:21:38 by nelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	init_frame_image(t_core *game)
{
	if (!(game->frame.image = mlx_new_image(game->mlx, \
		game->params->r[0], game->params->r[1])))
		error_creation_frame_image(game);
	game->frame.img_addr = mlx_get_data_addr(game->frame.image, \
		&game->frame.bpp, &game->frame.size_line, \
		&game->frame.endian);
}

void		init_textures(t_core *game)
{
	init_frame_image(game);
	if (!BONUS)
	{
		load_image(game, &game->west, game->params->we);
		load_image(game, &game->north, game->params->no);
		load_image(game, &game->south, game->params->so);
		load_image(game, &game->east, game->params->ea);
	}
	else
	{
		load_image(game, &game->wall, "./textures/wall.xpm");
		load_image(game, &game->wall_dirty, "./textures/wall_dirty.xpm");
		load_image(game, &game->sky, "./textures/sky_3.xpm");
		load_image(game, &game->floor, "./textures/floor.xpm");
		load_image(game, &game->face, "./textures/face.xpm");
	}
}

void		init_minimap(t_core *game)
{
	game->map.x_pos = 0;
	game->map.y_pos = 0;
	game->map.y_scale = game->params->r[1] / 3 / game->map.map_lines;
	game->map.x_scale = game->params->r[0] / 3 / game->map.map_colunms;
	game->map.scale = game->map.y_scale < game->map.x_scale ? \
		game->map.y_scale : game->map.x_scale;
}

void		init_window(t_core *game)
{
	int	scr_height;
	int	scr_width;

	mlx_get_screen_size(game->mlx, &scr_width, &scr_height);
	game->params->r[0] = game->params->r[0] >= scr_width ? scr_width : \
		game->params->r[0];
	game->params->r[1] = game->params->r[1] >= scr_height ? scr_height : \
		game->params->r[1];
	if (game->params->r[0] < 2)
		game->params->r[0] = 2;
	if (game->params->r[1] < 2)
		game->params->r[1] = 2;
	if (BONUS)
	{
		game->params->r[0] = scr_width < 1280 ? scr_width : 1280;
		game->params->r[1] = scr_height < 720 ? scr_height : 720;
	}
	if (game->save == -1)
		if (!(game->window = mlx_new_window(game->mlx, game->params->r[0], \
			game->params->r[1], "cub3D")))
			error_creation_window(game);
}

void		init_game_settings(t_core *game)
{
	game->center_x = game->params->r[0] / 2;
	game->center_y = game->params->r[1] / 2;
	game->player.x = 0;
	game->player.y = 0;
	game->shadow = 1.5;
	game->map.block_size = 50;
	game->player.angle = 3 * M_PI / 2;
	game->player.speed = game->map.block_size * 0.06;
	game->player.fast_speed = game->player.speed * 2;
	game->player.button_angle_speed = 0.045;
	game->player.mouse_angle_speed = 0.005;
	game->player.radius = game->map.block_size * 0.2;
	game->player.fov = M_PI / 3;
	game->player.num_rays = game->params->r[0];
	if (!(game->buffer = (t_ray_cast*)malloc(sizeof(t_ray_cast) * \
		game->player.num_rays)))
		error_malloc_buffer(game);
	game->player.delta_angle = game->player.fov / game->player.num_rays;
	game->map.map_lines = -1;
	game->map.map_colunms = 0;
	while (game->params->map[++game->map.map_lines])
		if ((int)ft_strlen(game->params->map[game->map.map_lines]) > \
			game->map.map_colunms)
			game->map.map_colunms = \
				ft_strlen(game->params->map[game->map.map_lines]);
}
