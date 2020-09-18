/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 15:36:39 by nelisabe          #+#    #+#             */
/*   Updated: 2020/09/18 21:09:31 by nelisabe         ###   ########.fr       */
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
	return (0);
}

// int		key_hook(int keycode, t_core *game)
// {
// 	printf("code -> %d\n", keycode);
// 	if (keycode == 0xff1b) //esc
// 	{
// 		// mlx_destroy_image(game->mlx, game->map.image);
// 		// mlx_destroy_image(game->mlx, game->player.pl_img.image);
// 		// mlx_clear_window(game->mlx, game->window);
// 		// mlx_destroy_window(game->mlx, game->window);
// 		exit(0);
// 	}
// 	if (keycode == 0xff51) //left
// 		game->player.angle -= 0.02;
// 		//draw_line(game, game->player.x, game->player.y, game->player.x + game->params->r[0] * cos(game->player.angle), game->player.y + game->params->r[1] * sin(game->player.angle));
// 	if (keycode == 0xff53) //right
// 		game->player.angle += 0.02;
// 		//draw_line(game, game->player.x, game->player.y, game->player.x + game->params->r[0] * cos(game->player.angle), game->player.y + game->params->r[1] * sin(game->player.angle));
// 	if (keycode == 0x0061) //a
// 		game->player.x -= game->player.speed;
// 	if (keycode == 0x0077) //w
// 		game->player.y -= game->player.speed;
// 	if (keycode == 0x0064) //d
// 		game->player.x += game->player.speed;
// 	if (keycode == 0x0073) //s
// 		game->player.y += game->player.speed;
// 	mlx_clear_window(game->mlx, game->window);
// 	player(game);
// 	return (0);
// }

int		key_pressed(int keycode, t_core *game)
{
	//printf("key_pressed %d\n", keycode);
	if (keycode == 0xff1b) //esc
	{
		// mlx_destroy_image(game->mlx, game->map.image);
		// mlx_destroy_image(game->mlx, game->player.pl_img.image);
		// mlx_clear_window(game->mlx, game->window);
		// mlx_destroy_window(game->mlx, game->window);
		exit(0);
	}
	if (keycode == 0xff51) //left
		game->button.left = 1;
		//draw_line(game, game->player.x, game->player.y, game->player.x + game->params->r[0] * cos(game->player.angle), game->player.y + game->params->r[1] * sin(game->player.angle));
	if (keycode == 0xff53) //right
		game->button.right = 1;
		//draw_line(game, game->player.x, game->player.y, game->player.x + game->params->r[0] * cos(game->player.angle), game->player.y + game->params->r[1] * sin(game->player.angle));
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
	//printf("key_realised %d\n", keycode);
	if (keycode == 0xff1b) //esc
	{
		// mlx_destroy_image(game->mlx, game->map.image);
		// mlx_destroy_image(game->mlx, game->player.pl_img.image);
		// mlx_clear_window(game->mlx, game->window);
		// mlx_destroy_window(game->mlx, game->window);
		exit(0);
	}
	if (keycode == 0xff51) //left
		game->button.left = 0;
		//draw_line(game, game->player.x, game->player.y, game->player.x + game->params->r[0] * cos(game->player.angle), game->player.y + game->params->r[1] * sin(game->player.angle));
	if (keycode == 0xff53) //right
		game->button.right = 0;
		//draw_line(game, game->player.x, game->player.y, game->player.x + game->params->r[0] * cos(game->player.angle), game->player.y + game->params->r[1] * sin(game->player.angle));
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
	if (game->button.left) //left
		game->player.angle -= 0.0005;
		//draw_line(game, game->player.x, game->player.y, game->player.x + game->params->r[0] * cos(game->player.angle), game->player.y + game->params->r[1] * sin(game->player.angle));
	if (game->button.right) //right
		game->player.angle += 0.0005;
		//draw_line(game, game->player.x, game->player.y, game->player.x + game->params->r[0] * cos(game->player.angle), game->player.y + game->params->r[1] * sin(game->player.angle));
	if (game->button.a) //a
		game->player.x -= game->player.speed;
	if (game->button.w) //w
		game->player.y -= game->player.speed;
	if (game->button.d) //d
		game->player.x += game->player.speed;
	if (game->button.s) //s
		game->player.y += game->player.speed;
	mlx_do_sync(game->mlx);
	mlx_clear_window(game->mlx, game->window);
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
	player(&game);
	//mlx_do_key_autorepeaton(game.mlx);
	mlx_do_key_autorepeatoff(game.mlx);
	mlx_hook(game.window, 2, 1L<<0, key_pressed, &game);
	mlx_hook(game.window, 3, 1L<<1, key_realised, &game);
	mlx_loop_hook(game.mlx, render, &game);
	mlx_loop(game.mlx);
	return (0);
}