/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 15:36:39 by nelisabe          #+#    #+#             */
/*   Updated: 2020/10/03 22:37:53 by nelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	int		init_handler(t_core *game)
{
	game->button.a = 0;
	game->button.s = 0;
	game->button.d = 0;
	game->button.w = 0;
	game->button.left = 0;
	game->button.right = 0;
	game->button.shift = 0;
	return (0);
}

int				key_pressed(int keycode, t_core *game)
{
	if (keycode == 0xff1b)
		esc_pressed(game);
	if (keycode == 0xff51)
		game->button.left = 1;
	if (keycode == 0xff53)
		game->button.right = 1;
	if (keycode == 0x0061)
		game->button.a = 1;
	if (keycode == 0x0077)
		game->button.w = 1;
	if (keycode == 0x0064)
		game->button.d = 1;
	if (keycode == 0x0073)
		game->button.s = 1;
	if (keycode == 0xffe1)
		game->button.shift = 1;
	return (0);
}

int				key_realised(int keycode, t_core *game)
{
	if (keycode == 0xff51)
		game->button.left = 0;
	if (keycode == 0xff53)
		game->button.right = 0;
	if (keycode == 0x0061)
		game->button.a = 0;
	if (keycode == 0x0077)
		game->button.w = 0;
	if (keycode == 0x0064)
		game->button.d = 0;
	if (keycode == 0x0073)
		game->button.s = 0;
	if (keycode == 0xffe1)
		game->button.shift = 0;
	return (0);
}


// int				mouse_pressed(int button, int x, int y, t_core *game)
// {
// 	printf("que?\n");
// 	return (0);
// }

int				mouse_moved(int x, int y, t_core *game)
{
	if (x > game->centerX)
		game->player.angle += game->player.mouse_angle_speed;
	if (x < game->centerX)
		game->player.angle -= game->player.mouse_angle_speed;
	return (0);
}

int				handler(t_core *game)
{
	init_handler(game);
	mlx_mouse_hide(game->mlx, game->window);
	//mlx_mouse_hook(game->window, mouse_pressed, game);
	mlx_hook(game->window, 6, 1L << 6, mouse_moved, game);
	mlx_hook(game->window, 2, 1L << 0, key_pressed, game);
	mlx_hook(game->window, 3, 1L << 1, key_realised, game);
	return (0);
}
