/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   standart_background.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 18:14:48 by nelisabe          #+#    #+#             */
/*   Updated: 2020/10/21 20:20:48 by nelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_back_colors(t_core *game)
{
	int	ceiling_color;
	int	floor_color;
	int	x;
	int y;

	ceiling_color = make_darker(0, game->params->c[0], game->params->c[1], \
		game->params->c[2]);
	floor_color = make_darker(0, game->params->f[0], game->params->f[1], \
		game->params->f[2]);
	y = -1;
	while (++y < game->params->r[1] / 2)
	{
		x = -1;
		while (++x < game->params->r[0])
			((int *)(game->frame.img_addr))[(int)y * game->params->r[0] + \
				(int)x] = ceiling_color;
	}
	y = game->params->r[1] / 2 - 1;
	while (++y < game->params->r[1])
	{
		x = -1;
		while (++x < game->params->r[0])
			((int *)(game->frame.img_addr))[(int)y * game->params->r[0] + \
				(int)x] = floor_color;
	}
}
