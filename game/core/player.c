/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 15:34:34 by nelisabe          #+#    #+#             */
/*   Updated: 2020/09/25 20:19:34 by nelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	void	movement(t_core *game)
{
	if (game->button.left)
		game->player.angle -= game->player.angle_speed;
	if (game->button.right)
		game->player.angle += game->player.angle_speed;
	if (game->button.a)
	{
		game->player.x += game->player.speed * sin(game->player.angle);
		game->player.y += -game->player.speed * cos(game->player.angle);
	}
	if (game->button.w)
	{
		game->player.x += game->player.speed * cos(game->player.angle);
		game->player.y += game->player.speed * sin(game->player.angle);
	}
	if (game->button.d)
	{
		game->player.x += -game->player.speed * sin(game->player.angle);
		game->player.y += game->player.speed * cos(game->player.angle);
	}
	if (game->button.s)
	{		
		game->player.x += -game->player.speed * cos(game->player.angle);
		game->player.y += -game->player.speed * sin(game->player.angle);
	}
}

int				player(t_core *game)
{
	movement(game);
	return (0);
}