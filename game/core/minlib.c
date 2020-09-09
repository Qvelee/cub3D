/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minlib.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 14:02:04 by nelisabe          #+#    #+#             */
/*   Updated: 2020/09/09 17:25:31 by nelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


int		draw_block(t_mlx *mlx, int *x, int y, int color)
{
	int xc;
	int yc;

	yc = y;
	while (++yc < y + 50)
	{
		xc = *x - 1;
		while (++xc < (*x) + 50)
			mlx_pixel_put(mlx->mlx_init, mlx->window, xc, yc, color);
	}
	(*x) += 50;
	return (0);
}

int		draw_map(t_pars *params, t_mlx *mlx)
{
	int index;
	int sindex;
	int y;
	int x;

	index = -1;
	x = 99;
	y = 99;
	while (params->map[++index])
	{
		sindex = -1;
		while (params->map[index][++sindex] != '\0')
			if (params->map[index][sindex] == '1')
				draw_block(mlx, &x, y, 0xBBBBBB);
			else if (params->map[index][sindex] == ' ')
				draw_block(mlx, &x, y, 0x002200);
			else //if (params->map[index][sindex] == '0')
				draw_block(mlx, &x, y, 0xEEEEEE);
		y += 49;
		x = 99;
	}
	return (0);
}

void	get_player_pos(t_player *player, t_pars *params)
{
	int index;
	int sindex;

	player->x = 99;
	player->y = 99;
	index = -1;
	while (params->map[++index])
	{
		sindex = -1;
		while (params->map[index][++sindex] != '\0')
		{
			if (params->map[index][sindex] == 'N')
				return ;
			player->x += 50;
		}
		player->x = 99;
		player->y += 50;
	}
}

int		init_lib(t_pars *params)
{
	t_mlx		mlx;
	t_player	player;
	int			index = -1;
	
	mlx.mlx_init = mlx_init();
	mlx.window = mlx_new_window(mlx.mlx_init, params->r[0], params->r[1], "cub3D");
	get_player_pos(&player, params);
	while (1)
	{
		draw_map(params, &mlx);
		draw_block(&mlx, &(player.x), player.y, 0xFF3300);
		mlx_loop(mlx.mlx_init);
	}
	return (0);
}