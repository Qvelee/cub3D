/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 15:34:34 by nelisabe          #+#    #+#             */
/*   Updated: 2020/09/19 13:41:55 by nelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				movement(t_core *game)
{
	if (game->button.left) //left
		game->player.angle -= game->player.angle_speed;
	if (game->button.right) //right
		game->player.angle += game->player.angle_speed;
	if (game->button.a) //a
	{
		game->player.x += game->player.speed * sin(game->player.angle);
		game->player.y += -game->player.speed * cos(game->player.angle);
	}
	if (game->button.w) //w
	{
		game->player.x += game->player.speed * cos(game->player.angle);
		game->player.y += game->player.speed * sin(game->player.angle);
	}
	if (game->button.d) //d
	{
		game->player.x += -game->player.speed * sin(game->player.angle);
		game->player.y += game->player.speed * cos(game->player.angle);
	}
	if (game->button.s) //s
	{		
		game->player.x += -game->player.speed * cos(game->player.angle);
		game->player.y += -game->player.speed * sin(game->player.angle);
	}
	return (0);
}

static	void	get_player_pos(t_core *game)
{
	static int	temp;
	int 		index;
	int 		sindex;

	if (temp)
		return ;
	game->player.x = 99;
	game->player.y = 99;
	index = -1;
	while (game->params->map[++index])
	{
		sindex = -1;
		while (game->params->map[index][++sindex] != '\0')
		{
			if (game->params->map[index][sindex] == 'N')
			{
				game->player.angle = 0;
				game->player.speed = 0.8;
				game->player.angle_speed = 0.005;
				temp = 1;
				return ;
			}
			game->player.x += 50;
		}
		game->player.x = 99;
		game->player.y += 50;
	}
}

int				player(t_core *game)
{
	get_player_pos(game);
	game->player.pl_img.image = mlx_new_image(game->mlx, \
		game->params->r[0], game->params->r[1]);
	game->player.pl_img.img_addr = mlx_get_data_addr(game->player.pl_img.image, \
		&game->player.pl_img.bpp, &game->player.pl_img.size_line, \
		&game->player.pl_img.endian);
	draw_circle(game, game->player.x, game->player.y, 10);
	draw_line(game, game->player.x, game->player.y, \
			game->player.x + /*game->params->r[0]*/200 * cos(game->player.angle), \
			game->player.y + /*game->params->r[0]*/200 * sin(game->player.angle));
	mlx_do_sync(game->mlx);
	mlx_put_image_to_window(game->mlx, game->window, game->player.pl_img.image, 0, 0);
	return (0);
}