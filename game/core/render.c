/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 17:02:12 by nelisabe          #+#    #+#             */
/*   Updated: 2020/10/23 16:43:55 by nelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	make_screenshot(t_core *game)
{
	unsigned char	*bmp;
	int				tmp;
	int				s;

	s = game->params->r[0] * game->params->r[1] * (game->frame.bpp / 8) + 54;
	if (!(bmp = (unsigned char *)malloc(sizeof(char) * s)))
		error_malloc(game);
	ft_bzero(bmp, s);
	ft_memcpy(&bmp[0], "BM", 2);
	tmp = 54;
	ft_memcpy(&bmp[10], &tmp, 4);
	tmp = 40;
	ft_memcpy(&bmp[14], &tmp, 4);
	ft_memcpy(&bmp[18], &game->params->r[0], 4);
	tmp = -game->params->r[1];
	ft_memcpy(&bmp[22], &tmp, 4);
	tmp = 1;
	ft_memcpy(&bmp[26], &tmp, 2);
	ft_memcpy(&bmp[28], &game->frame.bpp, 2);
	ft_memcpy(&bmp[54], game->frame.img_addr, s - 54);
	if ((tmp = open("sshot.bmp", O_CREAT | O_WRONLY | O_TRUNC, 0644)) == -1)
		error_creating_file(game, &bmp);
	s = write(tmp, bmp, s);
	free(bmp);
	close(tmp);
}

int			exit_cub3d(t_core *game)
{
	free(game->buffer);
	free_images(game);
	free_sprites(game);
	free_structer(game->params);
	if (game->frame.image)
		mlx_destroy_image(game->mlx, game->frame.image);
	if (game->window)
	{
		mlx_clear_window(game->mlx, game->window);
		mlx_destroy_window(game->mlx, game->window);
	}
	free(game->mlx);
	exit(0);
}

int			render(t_core *game)
{
	mlx_do_sync(game->mlx);
	if (BONUS && game->save == -1)
		mlx_mouse_move(game->mlx, game->window, game->center_x, \
			game->center_y);
	player(game);
	if (BONUS)
		set_sky(game);
	else
		set_back_colors(game);
	ray_casting(game);
	make_frame(game);
	if (BONUS)
		map(game);
	if (game->window)
		mlx_put_image_to_window(game->mlx, game->window, \
			game->frame.image, 0, 0);
	else
	{
		make_screenshot(game);
		exit_cub3d(game);
	}
	return (0);
}
