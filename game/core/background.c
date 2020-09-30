/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 16:59:26 by nelisabe          #+#    #+#             */
/*   Updated: 2020/09/29 15:23:30 by nelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_sky(t_core *game, t_ray_cast *ray, t_tex *texture)
{
	texture->step = game->sky.height / (game->params->r[1] / 2);
	texture->offset = 5 * ((ray->current_angle * 180 / M_PI) / \
		game->params->r[0]) - (int)(5 * (ray->current_angle * 180 / M_PI) / \
		game->params->r[0]);
	texture->x_screen = -1;
	texture->x_texture = texture->offset * texture->width;
	texture->x_texture = texture->x_texture < 0 ? texture->width - 1 + \
		texture->x_texture : texture->x_texture;
	while (++texture->x_screen < game->params->r[0])
	{
		texture->y_screen = -1;
		texture->y_texture = 0;
		while (++texture->y_screen < game->params->r[1] / 2)
		{
			texture->frame = game->frame.img_addr + \
				((int)texture->y_screen * game->frame.size_line + \
				(int)texture->x_screen * (game->frame.bpp / 8));
			texture->tex_image = texture->img.img_addr + \
				((int)texture->y_texture * texture->img.size_line + \
				(int)texture->x_texture * (texture->img.bpp / 8));
			*(unsigned int*)texture->frame = *(unsigned int*)texture->tex_image;
			texture->y_texture += texture->step;
		}
		texture->x_texture = texture->x_texture < texture->width - 1 ? \
			texture->x_texture + 1 : 0;
	}
}

void			set_floor(t_core *game, t_ray_cast *ray, int proj_height)
{
	t_tex	texture;
	
	texture = game->floor;
	double	dirX = -1.0;
	double	dirY = 0.0;
	double	planeX = 0.0;
	double	planeY = 0.60;

	for (int y = 0; y < game->params->r[1]; y++)
	{
		// rayDir for leftmost ray (x = 0) and rightmost ray (x = w)
		float rayDirX0 = dirX - planeX;
		float rayDirY0 = dirY - planeY;
		float rayDirX1 = dirX + planeX;
		float rayDirY1 = dirY + planeY;
		int p = y - game->params->r[1] / 2;

		// Vertical position of the camera.
		float posZ = 0.5 * game->params->r[1];

		// Horizontal distance from the camera to the floor for the current row.
		// 0.5 is the z position exactly in the middle between floor and ceiling.
		float rowDistance = posZ / p;
		
		// calculate the real world step vector we have to add for each x (parallel to camera plane)
		// adding step by step avoids multiplications with a weight in the inner loop
		float floorStepX = rowDistance * (rayDirX1 - rayDirX0) / game->params->r[1];
		float floorStepY = rowDistance * (rayDirY1 - rayDirY0) / game->params->r[1];

		// real world coordinates of the leftmost column. This will be updated as we step to the right.
		float floorX = game->player.x + rowDistance * rayDirX0;
		float floorY = game->player.y + rowDistance * rayDirY0;
		for(int x = 0; x < game->params->r[0]; ++x)
		{
			// the cell coord is simply got from the integer parts of floorX and floorY
			int cellX = (int)(floorX);
			int cellY = (int)(floorY);

			// get the texture coordinate from the fractional part
			int tx = (int)(texture.width * (floorX - cellX)) & (texture.width - 1);
			int ty = (int)(texture.height * (floorY - cellY)) & (texture.height - 1);

			floorX += floorStepX;
			floorY += floorStepY;

			// choose texture and draw the pixel
			int floorTexture = 3;
			int ceilingTexture = 6;

			// floor
			// color = texture[floorTexture][texture.width * ty + tx];
			// color = (color >> 1) & 8355711; // make a bit darker
			// buffer[y][x] = color;

			texture.frame = game->frame.img_addr + \
				((int)y * game->frame.size_line + \
				(int)x * (game->frame.bpp / 8));
			texture.tex_image = texture.img.img_addr + \
				((int)ty * texture.img.size_line + \
				(int)tx * (texture.img.bpp / 8));
			*(unsigned int*)texture.frame = *(unsigned int*)texture.tex_image;
			//ceiling (symmetrical, at screenHeight - y - 1 instead of y)
			// color = texture[ceilingTexture][texWidth * ty + tx];
			// color = (color >> 1) & 8355711; // make a bit darker
			// buffer[game->params->r[1] - y - 1][x] = color;
		}
	}
}

void	set_background(t_core *game, t_ray_cast *ray)
{
	set_sky(game, ray, &game->sky);
	set_floor(game, ray, 1);
	// game->color = 0x330000;
	// draw_rect(game, 0, game->params->r[1] / 2, \
		// game->params->r[0], game->params->r[1] / 2);
}
