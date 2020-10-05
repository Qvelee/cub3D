/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 15:44:00 by nelisabe          #+#    #+#             */
/*   Updated: 2020/10/05 14:21:20 by nelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				object_check(t_core *game, double x, double y, char object)
{
	int x_in_map;
	int	y_in_map;
	int	result;

	x_in_map = x / game->map.block_size;
	y_in_map = y / game->map.block_size;
	result = 0;
	if (y_in_map > game->map.map_lines - 1 || \
		x_in_map > game->map.map_colunms - 1)
		return (1);
	if (y_in_map < 0 || x_in_map < 0)
		return (1);
	if (object == 'W' || object == 'A')
		if (game->params->map[y_in_map][x_in_map] == '1' || \
			game->params->map[y_in_map][x_in_map] == '\0')
			result = 1;
	if ((object == 'S' || object == 'A') && !result)
		if (game->params->map[y_in_map][x_in_map] == '2')
			result = 1;
	return (result);
}

int				make_darker(double depth, int r, int g, int b)
{
	int		result;
	
	r /= (1 + depth * depth * 0.000005);
	g /= (1 + depth * depth * 0.000005);
	b /= (1 + depth * depth * 0.000005);
	result = (r << 16) + (g << 8) + b;
	return (result);
}

void	load_image(t_core *game, t_tex *texture, char *path)
{
	texture->img.image = mlx_xpm_file_to_image(game->mlx, \
		path, &texture->width, &texture->height);
	texture->img.img_addr = mlx_get_data_addr(texture->img.image, \
		&texture->img.bpp, &texture->img.size_line, \
		&texture->img.endian);
}
