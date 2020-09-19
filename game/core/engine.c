/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 15:36:39 by nelisabe          #+#    #+#             */
/*   Updated: 2020/09/19 13:41:57 by nelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		init_buttons(t_core *game)
{
	game->button.a = 0;
	game->button.s = 0;
	game->button.d = 0;
	game->button.w = 0;
	game->button.left = 0;
	game->button.right = 0;
	game->player.pl_img.image = NULL;
	return (0);
}

int		key_pressed(int keycode, t_core *game)
{
	if (keycode == 0xff1b) //esc
	{
		mlx_destroy_image(game->mlx, game->player.pl_img.image);
		mlx_clear_window(game->mlx, game->window);
		mlx_destroy_window(game->mlx, game->window);
		exit(0);
	}
	if (keycode == 0xff51) //left
		game->button.left = 1;
	if (keycode == 0xff53) //right
		game->button.right = 1;
	if (keycode == 0x0061) //a
		game->button.a = 1;
	if (keycode == 0x0077) //w
		game->button.w = 1;
	if (keycode == 0x0064) //d
		game->button.d = 1;
	if (keycode == 0x0073) //s
		game->button.s = 1;
	return (0);
}

int		key_realised(int keycode, t_core *game)
{
	if (keycode == 0xff51) //left
		game->button.left = 0;
	if (keycode == 0xff53) //right
		game->button.right = 0;
	if (keycode == 0x0061) //a
		game->button.a = 0;
	if (keycode == 0x0077) //w
		game->button.w = 0;
	if (keycode == 0x0064) //d
		game->button.d = 0;
	if (keycode == 0x0073) //s
		game->button.s = 0;
	return (0);
}

int		render(t_core *game)
{
	movement(game);
	mlx_do_sync(game->mlx);
	//mlx_clear_window(game->mlx, game->window);
	if (game->player.pl_img.image)
		mlx_destroy_image(game->mlx, game->player.pl_img.image);
	player(game);
	return (0);
}

int		engine(t_pars *pars)
{
	t_core game;

	game.params = pars;
	game.mlx = mlx_init();
	game.window = mlx_new_window(game.mlx, game.params->r[0], game.params->r[1], "cub3D");
	init_buttons(&game);
	//draw_map(&game);
	//player(&game);
	mlx_hook(game.window, 2, 1L<<0, key_pressed, &game);
	mlx_hook(game.window, 3, 1L<<1, key_realised, &game);
	mlx_loop_hook(game.mlx, render, &game);
	mlx_loop(game.mlx);
	return (0);
}