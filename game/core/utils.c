/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 15:44:00 by nelisabe          #+#    #+#             */
/*   Updated: 2020/10/21 20:22:38 by nelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		make_darker(double depth, int r, int g, int b)
{
	int	result;

	r /= (1 + depth * depth * 0.000005);
	g /= (1 + depth * depth * 0.000005);
	b /= (1 + depth * depth * 0.000005);
	result = (r << 16) + (g << 8) + b;
	return (result);
}

void	load_image(t_core *game, t_tex *texture, char *path)
{
	if (!path)
		error_malloc(game);
	if (!(texture->img.image = mlx_xpm_file_to_image(game->mlx, \
		path, &texture->width, &texture->height)))
		error_open_xpm_file(game, path);
	texture->img.img_addr = mlx_get_data_addr(texture->img.image, \
		&texture->img.bpp, &texture->img.size_line, \
		&texture->img.endian);
}

void	set_pixel(t_core *game, t_tex *texture, double depth)
{
	int color;

	color = ((int *)(texture->img.img_addr))\
			[(int)texture->y_texture * texture->width + \
			(int)texture->x_texture];
	if (color != 0x000000)
		((int *)(game->frame.img_addr))\
			[(int)texture->y_screen * game->params->r[0] + \
			(int)texture->x_screen] = make_darker(depth, \
			(color & 0xFF0000) >> 16, (color & 0x00FF00) >> 8, \
			color & 0x0000FF);
}

void	free_lst(t_list **lst)
{
	t_list *temp;

	if (!*lst)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		free(*lst);
		*lst = temp;
	}
}
