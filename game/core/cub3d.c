/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 19:22:50 by nelisabe          #+#    #+#             */
/*   Updated: 2020/09/20 17:28:51 by nelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//if last line not space map error why?

#include "cub3d.h"

static	void	init_game_settings(t_core *game)
{
	int	temp;
	
	game->map.block_size = 50;
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
	get_player_pos(&game);
	handler(&game);
	mlx_loop_hook(game.mlx, render, &game);
	mlx_loop(game.mlx);
	free_structer(&params);
	return (0);
}
