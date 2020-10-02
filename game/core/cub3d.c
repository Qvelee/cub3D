/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 19:22:50 by nelisabe          #+#    #+#             */
/*   Updated: 2020/10/02 20:31:05 by nelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//if last line not space map error why?
//edd many spaces

#include "cub3d.h"

static	void	init_images(t_core *game)
{
	game->west.img.image = mlx_xpm_file_to_image(game->mlx, \
		game->params->we, &game->west.width, &game->west.height);
	game->west.img.img_addr = mlx_get_data_addr(game->west.img.image, \
		&game->west.img.bpp, &game->west.img.size_line, &game->west.img.endian);
	game->north.img.image = mlx_xpm_file_to_image(game->mlx, \
		game->params->no, &game->north.width, &game->north.height);
	game->north.img.img_addr = mlx_get_data_addr(game->north.img.image, \
		&game->north.img.bpp, &game->north.img.size_line, &game->north.img.endian);
	game->south.img.image = mlx_xpm_file_to_image(game->mlx, \
		game->params->so, &game->south.width, &game->south.height);
	game->south.img.img_addr = mlx_get_data_addr(game->south.img.image, \
		&game->south.img.bpp, &game->south.img.size_line, &game->south.img.endian);
	game->east.img.image = mlx_xpm_file_to_image(game->mlx, \
		game->params->ea, &game->east.width, &game->east.height);
	game->east.img.img_addr = mlx_get_data_addr(game->east.img.image, \
		&game->east.img.bpp, &game->east.img.size_line, &game->east.img.endian);
	game->sky.img.image = mlx_xpm_file_to_image(game->mlx, \
		"./textures/sky3.xpm", &game->sky.width, &game->sky.height);
	game->sky.img.img_addr = mlx_get_data_addr(game->sky.img.image, \
		&game->sky.img.bpp, &game->sky.img.size_line, &game->sky.img.endian);
	game->floor.img.image = mlx_xpm_file_to_image(game->mlx, \
		"./textures/w.xpm", &game->floor.width, &game->floor.height);
	game->floor.img.img_addr = mlx_get_data_addr(game->floor.img.image, \
		&game->floor.img.bpp, &game->floor.img.size_line, &game->floor.img.endian);
}

static	void	init_game_settings(t_core *game)
{
	int	temp;
	
	game->map.block_size = 50;
	game->player.angle = 3 * M_PI / 2;
	game->player.speed = 2;
	game->player.angle_speed = 0.03;
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

static	void	get_player_pos(t_core *game)
{
	int 		index;
	int 		sindex;

	game->player.x = 0;
	game->player.y = 0;
	index = -1;
	while (game->params->map[++index])
	{
		sindex = -1;
		while (game->params->map[index][++sindex] != '\0')
		{
			if (game->params->map[index][sindex] == 'N')
			{
				game->player.x += game->map.block_size / 2;
				game->player.y += game->map.block_size / 2;
				return ;
			}
			game->player.x += game->map.block_size;
		}
		game->player.x = 0;
		game->player.y += game->map.block_size;
	}
}

int				cub3d(char *path)
{
	t_pars params;
	t_core game;

	if (parser(path, &params))
		return (0);
	game.params = &params;
	game.mlx = mlx_init();
	game.window = mlx_new_window(game.mlx, game.params->r[0], game.params->r[1], "cub3D");
	init_game_settings(&game);
	init_images(&game);
	get_player_pos(&game);
	mlx_mouse_hide(game.mlx, game.window);
	handler(&game);
	mlx_loop_hook(game.mlx, render, &game);
	mlx_loop(game.mlx);
	free_structer(&params);
	return (0);
}
