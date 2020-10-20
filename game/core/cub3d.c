/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngameisabe <ngameisabe@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 19:22:50 by ngameisabe          #+#    #+#             */
/*   Updated: 2020/10/15 19:29:52 by ngameisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//i can walk through corners!!!!

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

static	int		check_flag(char *flag)
{
	if (!flag)
		return (-1);
	if (ft_strncmp(flag, "--save", 6 + ft_strlen(flag)))
	{
		ft_putendl_fd("Error", 1);
		ft_putendl_fd("cub3d: Invalid flag", 1);
		return (0);
	}
	return (1);
}

int				cub3d(char *path, char *flag)
{
	t_pars params;
	t_core game;

	if (!(game.save = check_flag(flag)))
		return (0);
	if (parser(path, &params))
		return (0);
	game.params = &params;
	init_pointers(&game);
	if (!(game.mlx = mlx_init()))
		error_mlx_init(&game);
	init_window(&game);
	init_game_settings(&game);
	init_textures(&game);
	init_sprites(&game);
	init_map(&game);
	get_player_pos(&game);
	handler(&game);
	mlx_loop_hook(game.mlx, render, &game);
	mlx_loop(game.mlx);
	return (0);
}
