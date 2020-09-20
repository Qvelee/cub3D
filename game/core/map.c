/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 15:34:32 by nelisabe          #+#    #+#             */
/*   Updated: 2020/09/20 15:31:07 by nelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	void	init_game_settings(t_core *game)
{
	int	temp;
	
	game->player.angle = 0;
	game->player.speed = 0.6;
	game->player.angle_speed = 0.0159;
	game->player.fov = M_PI / 3;
	game->player.num_rays = game->params->r[0] / 2;
	game->player.delta_angle = game->player.fov / game->player.num_rays;
	game->map.map_lines = -1;
	game->map.map_colunms = 0;
	while (game->params->map[++game->map.map_lines])
		if ((temp = ft_strlen(game->params->map[game->map.map_lines])) > \
			game->map.map_colunms)
			game->map.map_colunms = temp;
}

static	void	get_player_pos(t_core *game)
{
	static int	temp;
	int 		index;
	int 		sindex;

	if (temp)
		return ;
	game->player.x = 0;
	game->player.y = 0;
	game->map.block_size = 50;
	index = -1;
	while (game->params->map[++index])
	{
		sindex = -1;
		while (game->params->map[index][++sindex] != '\0')
		{
			if (game->params->map[index][sindex] == 'N')
			{
				init_game_settings(game);
				game->player.x += game->map.block_size / 2;
				game->player.y += game->map.block_size / 2;
				temp = 1;
				return ;
			}
			game->player.x += game->map.block_size;
		}
		game->player.x = 0;
		game->player.y += game->map.block_size;
	}
}

int		map(t_core *game)
{
	int index;
	int sindex;
	int x;
	int y;
	
	get_player_pos(game);
	// game->frame.image = mlx_new_image(game->mlx, \
	// 	game->map.map_colunms * game->map.block_size, \
	// 	game->map.map_lines * game->map.block_size);
	game->frame.image = mlx_new_image(game->mlx, \
		game->params->r[0], game->params->r[1]);
	game->frame.img_addr = mlx_get_data_addr(game->frame.image, \
		&game->frame.bpp, &game->frame.size_line, \
		&game->frame.endian);
	// index = -1;
	// x = 0;
	// y = 0;
	// while (game->params->map[++index])
	// {
	// 	sindex = -1;
	// 	while (game->params->map[index][++sindex] != '\0')
	// 	{
	// 		if (game->params->map[index][sindex] == '1')
	// 			draw_block(game, x, y, 0x007700);
	// 		else if (game->params->map[index][sindex] == ' ')
	// 			draw_block(game, x, y, 0x000000);
	// 		else
	// 			draw_block(game, x, y, 0x003333);
	// 		x += game->map.block_size;
	// 	}
	// 	y += game->map.block_size;
	// 	x = 0;
	// }
	return (0);
}