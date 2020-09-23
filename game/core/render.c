/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 17:02:12 by nelisabe          #+#    #+#             */
/*   Updated: 2020/09/23 17:36:24 by nelisabe         ###   ########.fr       */
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

void	images(t_core *game)
{
	static	int	temp;
	static	int t0;
	static	int t1;
	static	int t2;
	static	int t3;
	
	if (!t0)
	{
		game->west.img.image = mlx_xpm_file_to_image(game->mlx, \
			game->params->we, &game->west.width, &game->west.height);
		game->west.img.img_addr = mlx_get_data_addr(game->west.img.image, \
			&game->west.img.bpp, &game->west.img.size_line, &game->west.img.endian);
		t0 = 1;
	}
	if (!t1)
	{
		game->north.img.image = mlx_xpm_file_to_image(game->mlx, \
			game->params->no, &game->north.width, &game->north.height);
		game->north.img.img_addr = mlx_get_data_addr(game->north.img.image, \
			&game->north.img.bpp, &game->north.img.size_line, &game->north.img.endian);
		t1 = 1;
	}
	if (!t2)
	{
		game->south.img.image = mlx_xpm_file_to_image(game->mlx, \
			game->params->so, &game->south.width, &game->south.height);
		game->south.img.img_addr = mlx_get_data_addr(game->south.img.image, \
			&game->south.img.bpp, &game->south.img.size_line, &game->south.img.endian);
		t2 = 1;
	}
	if (!t3)
	{
		game->east.img.image = mlx_xpm_file_to_image(game->mlx, \
			game->params->ea, &game->east.width, &game->east.height);
		game->east.img.img_addr = mlx_get_data_addr(game->east.img.image, \
			&game->east.img.bpp, &game->east.img.size_line, &game->east.img.endian);
		t3 = 1;
	}
	if (!temp)
	{
		if (game->frame.image)
			mlx_destroy_image(game->mlx, game->frame.image);
		game->frame.image = mlx_new_image(game->mlx, \
			game->params->r[0], game->params->r[1]);
		game->frame.img_addr = mlx_get_data_addr(game->frame.image, \
			&game->frame.bpp, &game->frame.size_line, \
			&game->frame.endian);
			temp = 1;
	}
}

int		render(t_core *game)
{
	images(game);
	//map(game);
	player(game);
	mlx_put_image_to_window(game->mlx, game->window, game->frame.image, 0, 0);
	mlx_do_sync(game->mlx);
	return (0);
}
