/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 15:34:34 by nelisabe          #+#    #+#             */
/*   Updated: 2020/10/03 16:18:55 by nelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	void	collision(t_core *game, double x_move, double y_move)
{
	const	int		y_dir = y_move < 0 ? -1 : 1;
	const	int		x_dir = x_move < 0 ? -1 : 1;
	
	if (wall_check(game, game->player.x + x_dir * game->player.radius + \
		x_move, game->player.y + y_dir * game->player.radius + y_move))
	{
		return ; 
	}
	else
	{
		game->player.x += x_move;
		game->player.y += y_move;
	}
}

static	void	movement(t_core *game)
{
	if (game->button.left)
		game->player.angle -= game->player.angle_speed;
	if (game->button.right)
		game->player.angle += game->player.angle_speed;
	if (game->button.a)
		collision(game, game->player.cur_speed * sin(game->player.angle), \
			-game->player.cur_speed * cos(game->player.angle));
	if (game->button.w)
		collision(game, game->player.cur_speed * cos(game->player.angle), \
			game->player.cur_speed * sin(game->player.angle));
	if (game->button.d)
		collision(game, -game->player.cur_speed * sin(game->player.angle), \
			game->player.cur_speed * cos(game->player.angle));
	if (game->button.s)
		collision(game, -game->player.speed * cos(game->player.angle), \
			-game->player.speed * sin(game->player.angle));
}

int				player(t_core *game)
{
	game->player.cur_speed = game->button.shift ? \
		game->player.fast_speed : game->player.speed;
	movement(game);
	return (0);
}
