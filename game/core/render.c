/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 17:02:12 by nelisabe          #+#    #+#             */
/*   Updated: 2020/10/15 19:51:09 by nelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		esc_pressed(t_core *game)
{
	mlx_destroy_image(game->mlx, game->frame.image);
	if (game->save == -1)
	{
		mlx_clear_window(game->mlx, game->window);
		mlx_destroy_window(game->mlx, game->window);
	}
	free(game->buffer);
	exit(0);
}

static void  make_screenshot(t_core *game)
{
	unsigned char	*bmp;
	int				fd;
	int				size;

	size = game->params->r[0] * game->params->r[1] * (game->frame.bpp / 8) + 54;
	bmp = (unsigned char *)malloc(sizeof(char) * size);
	ft_bzero(bmp, size);
	ft_memcpy(&bmp[0], "BM", 2);
	fd = 54;
	ft_memcpy(&bmp[10], &fd, 4);
	fd = 40;
	ft_memcpy(&bmp[14], &fd, 4);
	ft_memcpy(&bmp[18], &game->params->r[0], 4);
	fd = -game->params->r[1];
	ft_memcpy(&bmp[22], &fd, 4);
	fd = 1;
	ft_memcpy(&bmp[26], &fd, 2);
	ft_memcpy(&bmp[28], &game->frame.bpp, 2);
	ft_memcpy(&bmp[54], game->frame.img_addr, size - 54);
	fd = open("screenshot.bmp", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	size = write(fd, bmp, size);
	free(bmp);
	close(fd);
}

int		render(t_core *game)
{
	static int	temp;

	if (BONUS && game->save == -1)
		mlx_mouse_move(game->mlx, game->window, game->centerX, \
			game->centerY);
	player(game);
	ray_casting(game);
	make_frame(game);
	if (BONUS)
		map(game);
	if (game->save == -1)
		mlx_put_image_to_window(game->mlx, game->window, \
			game->frame.image, 0, 0);
	else
	{
		make_screenshot(game);
		esc_pressed(game);
	}
	mlx_do_sync(game->mlx);
	return (0);
}
