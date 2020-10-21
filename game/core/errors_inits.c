/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_inits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 13:44:46 by nelisabe          #+#    #+#             */
/*   Updated: 2020/10/21 19:43:44 by nelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	error_creation_frame_image(t_core *game)
{
	free_structer(game->params);
	if (game->window)
		mlx_destroy_window(game->mlx, game->window);
	free(game->mlx);
	free(game->buffer);
	ft_putendl_fd("Error", 1);
	ft_putendl_fd("cub3D: Frame image creation fail", 1);
	exit(0);
}

void	error_malloc_buffer(t_core *game)
{
	free_structer(game->params);
	if (game->window)
		mlx_destroy_window(game->mlx, game->window);
	free(game->mlx);
	ft_putendl_fd("Error", 1);
	ft_putendl_fd("cub3D: Memory allocation fail", 1);
	exit(0);
}

void	error_mlx_init(t_core *game)
{
	free_structer(game->params);
	ft_putendl_fd("Error", 1);
	ft_putendl_fd("cub3D: Failed to create connection with display", 1);
	exit(0);
}

void	error_creation_window(t_core *game)
{
	free_structer(game->params);
	free(game->mlx);
	ft_putendl_fd("Error", 1);
	ft_putendl_fd("cub3D: Failed to create window", 1);
	exit(0);
}
