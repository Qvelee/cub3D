/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 19:22:50 by nelisabe          #+#    #+#             */
/*   Updated: 2020/10/07 16:55:37 by nelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//if last line not space map error why?
//edd many spaces
//i can walk through corners!!!!
//make nickname with username

#include "cub3d.h"

static	int		check_for_player(t_core *game, char block)
{
	if (block == 'N')
		game->player.angle = 3 * M_PI / 2;
	else if (block == 'W')
		game->player.angle = M_PI;
	else if (block == 'S')
		game->player.angle = M_PI / 2;
	else if (block == 'E')
		game->player.angle = 0;
	else
		return (0);
	return (1);
}

static	void	get_player_pos(t_core *game)
{
	int	index;
	int	sindex;

	index = -1;
	while (game->params->map[++index])
	{
		sindex = -1;
		while (game->params->map[index][++sindex] != '\0')
		{
			if (check_for_player(game, game->params->map[index][sindex]))
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
	game.window = mlx_new_window(game.mlx, game.params->r[0], \
		game.params->r[1], "cub3D");
	init_game_settings(&game);
	init_textures(&game);
	init_sprites(&game);
	init_map(&game);
	get_player_pos(&game);
	handler(&game);
	mlx_loop_hook(game.mlx, render, &game);
	mlx_loop(game.mlx);
	free_structer(&params);
	return (0);
}
