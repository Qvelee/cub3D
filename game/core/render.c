/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 17:02:12 by nelisabe          #+#    #+#             */
/*   Updated: 2020/10/10 19:48:54 by nelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	esc_pressed(t_core *game)
{
	mlx_destroy_image(game->mlx, game->frame.image);
	mlx_clear_window(game->mlx, game->window);
	mlx_destroy_window(game->mlx, game->window);
	free(game->buffer);
	exit(0);
}

int		render(t_core *game)
{
	static int	temp;

	mlx_mouse_move(game->mlx, game->window, game->centerX, \
		game->centerY);
	player(game);
	ray_casting(game);
	make_frame(game);
	map(game);
	mlx_put_image_to_window(game->mlx, game->window, game->frame.image, 0, 0);
	mlx_do_sync(game->mlx);
	return (0);
}
