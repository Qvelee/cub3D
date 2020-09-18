/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 15:34:34 by nelisabe          #+#    #+#             */
/*   Updated: 2020/09/18 21:09:33 by nelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
				game->player.speed = 0.03;
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
	//printf("x = %d\n y = %d\n", game->player.x, game->player.y);
	draw_circle(game, game->player.x, game->player.y, 10);
	draw_line(game, game->player.x, game->player.y, \
			game->player.x + game->params->r[0] * cos(game->player.angle), \
			game->player.y + game->params->r[0] * sin(game->player.angle));
	return (0);
}