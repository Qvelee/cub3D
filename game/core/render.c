/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 17:02:12 by nelisabe          #+#    #+#             */
/*   Updated: 2020/09/25 19:24:09 by nelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	esc_pressed(t_core *game)
{
	mlx_destroy_image(game->mlx, game->frame.image);
	mlx_clear_window(game->mlx, game->window);
	mlx_destroy_window(game->mlx, game->window);
	exit(0);
}

void	pixel_put(t_img image, int x, int y, int color)
{
	char			*dst;

	if (y < 0 || x < 0)
		return ;
	dst = image.img_addr + (y * image.size_line + x * (image.bpp / 8));
	*(unsigned int*)dst = color;
}

int		render(t_core *game)
{
	static int	temp;

	if (game->frame.image)
		mlx_destroy_image(game->mlx, game->frame.image);
	game->frame.image = mlx_new_image(game->mlx, \
		game->params->r[0], game->params->r[1]);
	game->frame.img_addr = mlx_get_data_addr(game->frame.image, \
		&game->frame.bpp, &game->frame.size_line, \
		&game->frame.endian);
	player(game);
	ray_casting(game);
	mlx_put_image_to_window(game->mlx, game->window, game->frame.image, 0, 0);
	mlx_do_sync(game->mlx);
	return (0);
}
