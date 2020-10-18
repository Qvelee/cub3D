/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_load_images.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 15:05:16 by nelisabe          #+#    #+#             */
/*   Updated: 2020/10/18 20:28:00 by nelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	error_open_xpm_file(t_core *game, char *path)
{
	ft_putendl_fd("Error", 1);
	ft_putstr_fd("cub3D: Error open \"", 1);
	ft_putstr_fd(path, 1);
	perror("\" image");
	mlx_destroy_window(game->mlx, game->window);
	free_images(game);
	free_sprites(game);
	mlx_destroy_image(game->mlx, game->frame.image);
	free(game->mlx);
	free(game->buffer);
	free_structer(game->params);
	exit(0);
}
