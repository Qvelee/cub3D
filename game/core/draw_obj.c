/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 15:44:00 by nelisabe          #+#    #+#             */
/*   Updated: 2020/09/20 14:26:17 by nelisabe         ###   ########.fr       */
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

void	draw_block(t_core *game, int x, int y, int color)
{
	int xc;
	int yc;
	
	yc = y;
	while (yc < y + game->map.block_size)
	{
		xc = x;
		while (xc < x + game->map.block_size)
			pixel_put(game->frame, xc++, yc, color);
		yc++;
	}
}

void	draw_rect(t_core *game, int x, int y, int a, int b, int color)
{
	int xc;
	int yc;

	yc = y;
	while (yc < y + b)
	{
		xc = x;
		while (xc < x + a)
			pixel_put(game->frame, xc++, yc, color);
		yc++;
	}
}

void	draw_circle(t_core *game, int x0, int y0, int radius)
{
	int x = 0;
	int y = radius;
	int delta = 1 - 2 * radius;
	int error = 0;
	
	while(y >= 0)
	{
		pixel_put(game->frame, x0 + x, y0 + y, 0x0033FF);
		pixel_put(game->frame, x0 + x, y0 - y, 0x0033FF);
		pixel_put(game->frame, x0 - x, y0 + y, 0x0033FF);
		pixel_put(game->frame, x0 - x, y0 - y, 0x0033FF);
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
    pixel_put(game->frame, x2, y2, 0x0033FF);
    while(x1 != x2 || y1 != y2) 
   {
		pixel_put(game->frame, x1, y1, 0x0033FF);
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
