/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 15:34:32 by nelisabe          #+#    #+#             */
/*   Updated: 2020/10/04 20:04:56 by nelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	void	set_pixel(t_core *game, t_tex *texture)
{
	int	color;
	
	color = ((int *)(texture->img.img_addr))\
			[(int)texture->y_texture * texture->width + \
			(int)texture->x_texture];
	if (color == 0)
		return ;
	if (texture == &game->floor)
		color = make_darker(300, (color & 0xFF0000) >> 16, (color & 0x00FF00) >> 8, \
			(color & 0x0000FF));
	((int *)(game->frame.img_addr))\
			[(int)texture->y_screen * game->params->r[0] + \
			(int)texture->x_screen] = color;
}

static	void	draw_block(t_core *game, t_tex *texture, int x, int y)
{
	double step_x;
	double step_y;

	texture->y_screen = y;
	step_x = (double)texture->width / (double)game->map.scale;
	step_y = (double)texture->height / (double)game->map.scale;
	texture->y_texture = 0;
	while (texture->y_screen < y + game->map.scale)
	{
		texture->x_screen = x;
		texture->x_texture = 0;
		while (texture->x_screen < x + game->map.scale)
		{
			set_pixel(game, texture);
			texture->x_texture += step_x;
			texture->x_screen++;
		}
		texture->y_screen++;
		texture->y_texture += step_y;
	}
}

static	void	draw_player(t_core *game)
{
	int	pl_x;
	int	pl_y;

	pl_x = game->player.x / game->map.block_size * game->map.scale;
	pl_y = game->player.y / game->map.block_size * game->map.scale;
	pl_x -= game->map.scale / 2;
	pl_y -= game->map.scale / 2;
	draw_block(game, &game->face, pl_x, pl_y);
}

int		map(t_core *game)
{
	int index;
	int sindex;
	int	x_pos;
	int	y_pos;
	
	index = -1;
	x_pos = game->map.x_pos;
	y_pos = game->map.y_pos;
	while (game->params->map[++index])
	{
		sindex = -1;
		while (game->params->map[index][++sindex] != '\0')
		{
			if (game->params->map[index][sindex] == '1')
				draw_block(game, &game->north, x_pos, y_pos);
			else
				draw_block(game, &game->floor, x_pos, y_pos);
			x_pos += game->map.scale;
		}
		y_pos += game->map.scale;
		x_pos = 0;
	}
	draw_player(game);
	return (0);
}