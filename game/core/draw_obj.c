/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 15:44:00 by nelisabe          #+#    #+#             */
/*   Updated: 2020/09/19 13:13:14 by nelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	pixel_put(t_img image, int x, int y, int color)
{
	char			*dst;
	
	if (y < 0 || x < 0)
		return ;
	dst = image.img_addr + (y * image.size_line + x * (image.bpp / 8));
	*(unsigned int*)dst = color;
}

void	draw_circle(t_core *game, int x0, int y0, int radius)
{
	int x = 0;
	int y = radius;
	int delta = 1 - 2 * radius;
	int error = 0;
	while(y >= 0)
	{
		// mlx_pixel_put(game->mlx, game->window, x0 + x, y0 + y, 0x0033FF);
		// mlx_pixel_put(game->mlx, game->window, x0 + x, y0 - y, 0x0033FF);
		// mlx_pixel_put(game->mlx, game->window, x0 - x, y0 + y, 0x0033FF);
		// mlx_pixel_put(game->mlx, game->window, x0 - x, y0 - y, 0x0033FF);
		pixel_put(game->player.pl_img, x0 + x, y0 + y, 0x0033FF);
		pixel_put(game->player.pl_img, x0 + x, y0 - y, 0x0033FF);
		pixel_put(game->player.pl_img, x0 - x, y0 + y, 0x0033FF);
		pixel_put(game->player.pl_img, x0 - x, y0 - y, 0x0033FF);
		error = 2 * (delta + y) - 1;
		if(delta < 0 && error <= 0)
		{
			++x;
			delta += 2 * x + 1;
			continue;
		}
		error = 2 * (delta - x) - 1;
		if(delta > 0 && error > 0)
		{
			--y;
			delta += 1 - 2 * y;
			continue;
		}
		++x;
		delta += 2 * (x - y);
		--y;
	}
}

void	draw_line(t_core *game, int x1, int y1, int x2, int y2)
{
	const int deltaX = abs(x2 - x1);
    const int deltaY = abs(y2 - y1);
    const int signX = x1 < x2 ? 1 : -1;
    const int signY = y1 < y2 ? 1 : -1;

	int error = deltaX - deltaY;
	//mlx_pixel_put(game->mlx, game->window, x2, y2, 0x0033FF);
    pixel_put(game->player.pl_img, x2, y2, 0x0033FF);
    while(x1 != x2 || y1 != y2) 
   {
		//mlx_pixel_put(game->mlx, game->window, x1, y1, 0x0033FF);
		pixel_put(game->player.pl_img, x1, y1, 0x0033FF);
        const int error2 = error * 2;
        if(error2 > -deltaY) 
        {
            error -= deltaY;
            x1 += signX;
        }
        if(error2 < deltaX) 
        {
            error += deltaX;
            y1 += signY;
        }
    }
}
