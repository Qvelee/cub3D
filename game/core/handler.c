/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 15:36:39 by nelisabe          #+#    #+#             */
/*   Updated: 2020/09/20 17:18:23 by nelisabe         ###   ########.fr       */
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
	game->frame.image = NULL;
	return (0);
}

int				key_pressed(int keycode, t_core *game)
{
	if (keycode == 0xff1b) //esc
		esc_pressed(game);
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

int				key_realised(int keycode, t_core *game)
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

int				handler(t_core *game)
{
	init_handler(game);
	mlx_hook(game->window, 2, 1L<<0, key_pressed, game);
	mlx_hook(game->window, 3, 1L<<1, key_realised, game);
	return (0);
}