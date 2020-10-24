/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_memory.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 15:05:16 by nelisabe          #+#    #+#             */
/*   Updated: 2020/10/24 14:22:25 by nelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	error_creating_file(t_core *game, unsigned char **memory)
{
	ft_putendl_fd("Error", 1);
	ft_putendl_fd("cub3D: Creating file fail", 1);
	free(*memory);
	exit_cub3d(game);
}

void	error_malloc(t_core *game)
{
	ft_putendl_fd("Error", 1);
	ft_putendl_fd("cub3D: Memory allocation fail", 1);
	exit_cub3d(game);
}

void	error_newlst(t_core *game, t_list **list)
{
	ft_putendl_fd("Error", 1);
	ft_putendl_fd("cub3D: Memory allocation fail", 1);
	free_lst(list);
	exit_cub3d(game);
}

void	error_newlsts(t_core *game, t_list **list_1, t_list **list_2)
{
	ft_putendl_fd("Error", 1);
	ft_putendl_fd("cub3D: Memory allocation fail", 1);
	free_lst(list_1);
	free_lst(list_2);
	exit_cub3d(game);
}

void	error_open_xpm_file(t_core *game, char *path)
{
	ft_putendl_fd("Error", 1);
	ft_putstr_fd("cub3D: Error open \"", 1);
	ft_putstr_fd(path, 1);
	perror("\" image");
	if (game->window)
		mlx_destroy_window(game->mlx, game->window);
	free_images(game);
	free_sprites(game);
	mlx_destroy_image(game->mlx, game->frame.image);
	free(game->mlx);
	free(game->buffer);
	free_structer(game->params);
	exit(0);
}
