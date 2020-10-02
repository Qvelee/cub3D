/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 16:59:26 by nelisabe          #+#    #+#             */
/*   Updated: 2020/10/02 20:16:00 by nelisabe         ###   ########.fr       */
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

void			set_floor(t_core *game, t_ray_cast *ray, int proj_height, double dist)
{
	t_tex	texture;

	static int t;

	// if (proj_height >= game->params->r[1])
	// 	return ;

	texture = game->floor;
	//printf("rx ry %f %f\n", ray->x, ray->y);
	
	double	floor_x = ray->x / game->map.block_size;
	double	floor_y = ray->y / game->map.block_size;

	// printf("fx-> %f\n", floor_x);
	// printf("fy-> %f\n", floor_y);

	//printf("x -> %f\n", floor_x);
	//printf("y -> %f\n", floor_y);
	
	texture.x_screen = ray->num_rays;
	texture.y_screen = game->params->r[1] / 2 + proj_height / 2;
	
	//printf("screen x -> %f\n", texture.x_screen);
	//printf("screen y -> %f\n", texture.y_screen);

	double	distWall;
	double	currentDist;
	
	distWall = ray->depth / game->map.block_size;

	//printf("distWall -> %f / 50 = %f\n", ray->depth, distWall);

	int	lineheight = (int)(game->params->r[1] / distWall);

	if ((texture.y_screen = lineheight / 2 + game->params->r[1] / 2) >= game->params->r[1])
            texture.y_screen = game->params->r[1] - 1;
            if (texture.y_screen < 0) texture.y_screen = game->params->r[1];
	// FILE * pFile;
    // 	pFile = fopen ("nelisabe.txt","w");

	for(int y = (int)texture.y_screen + 1; y < game->params->r[1]; y++)
	{
		currentDist = game->params->r[1] / (2.0 * y - game->params->r[1]);

		//printf("currentDist -> 800 / (2 * %d - 800) = %f\n", y, currentDist);
		/* 800 / (2 * 450 - 800) = 8
		*/
        double	weight = currentDist / distWall;

		//printf("weight -> %f / %f = %f\n", currentDist, distWall, weight);

		/* 
		*/
		
        double currentFloorX = weight * floor_x + \
			(1.0 - weight) * game->player.x / game->map.block_size;

		//printf("currentFloorX -> %f * %f + (1.0 - %f) * %f = %f\n", weight, floor_x, weight, game->player.x / 50.0, currentFloorX);
		
        double currentFloorY = weight * floor_y + \
			(1.0 - weight) * game->player.y / game->map.block_size;
		// if (texture.x_screen == 600)
		// {
		// 	fprintf(pFile,"x = %f y = %d\n", texture.x_screen, y);
        // 	fprintf(pFile,"curX->%f\n", currentFloorX);
        // 	fprintf(pFile,"curY->%f\n", currentFloorY);
		// 	fprintf(pFile,"curDis = %f\n", currentDist);
		// 	fprintf(pFile,"w = %f\n", weight);
		// }
		
		// printf("curX->%f\n", currentFloorX);
		// printf("curY->%f\n", currentFloorY);
		// printf("y->%d\n", y);
		//printf("currentFloorY -> %f * %f + (1.0 - %f) * %f = %f\n", weight, floor_y, weight, game->player.y / 50.0, currentFloorY);

		int floorTexX, floorTexY;
        floorTexX = (int)(currentFloorX * texture.width) % texture.width;
		// currentFloorX -= (int)currentFloorX;e
		// floorTexX = currentFloorX * texture.width;
		//printf("floorTexX -> %f * %d = %d\n", currentFloorX, texture.width, floorTexX);
		
        floorTexY = (int)(currentFloorY * texture.height) % texture.height;
		// currentFloorY -= (int)currentFloorY;
		// floorTexY = currentFloorY * texture.height;
		// if (texture.x_screen == 600)
		// {
		// 	fprintf(pFile,"floorTexX = %d\n", floorTexX);
		// 	fprintf(pFile,"floorTexY = %d\n", floorTexY);
		// 	fprintf(pFile, "lineheigth = %d\n", proj_height);
		// }
		//printf("floorTexY -> %f * %d = %d\n", currentFloorY, texture.height, floorTexY);

		((int *)(game->frame.img_addr))[y * game->params->r[0] + (int)texture.x_screen] = \
			((int *)(texture.img.img_addr))[floorTexY * texture.width + floorTexX];

		// ((int *)(game->frame.img_addr))[(game->params->r[1] - y) * game->params->r[0] + (int)texture.x_screen] = \
			// ((int *)(game->south.img.img_addr))[floorTexY * texture.width + floorTexX];
	}
	// if (texture.x_screen == 600)
	// {
	// 	fclose(pFile);
	// 	if (!t)
	// 		if (getchar() == 'e')
	// 			exit(0);
	// }
}

void			set_floor1(t_core *game, t_ray_cast *ray)
{
	t_tex	texture;
	
	texture = game->floor;
	double	dirX = cos(game->player.angle);
	double	dirY = sin(game->player.angle);
	double	planeX = (dirX * cos(M_PI / 2) - dirY * sin(M_PI / 2)) * 0.65; //* tan(M_PI / 6);
	double	planeY = (dirX * sin(M_PI / 2) + dirY * cos(M_PI / 2)) * 0.65; //* tan(M_PI / 6);

	// rayDir for leftmost ray (x = 0) and rightmost ray (x = w)
	float rayDirX0 = dirX - planeX;
	float rayDirY0 = dirY - planeY;
	float rayDirX1 = dirX + planeX;
	float rayDirY1 = dirY + planeY;

	// Vertical position of the camera.
	float posZ = game->params->r[1] / 2;
	for (int y = game->params->r[1] / 2; y < game->params->r[1]; y++)
	{
		// Current y position compared to the center of the screen (the horizon)
		int p = y - game->params->r[1] / 2;

		// Horizontal distance from the camera to the floor for the current row.
		// 0.5 is the z position exactly in the middle between floor and ceiling.
		float rowDistance = posZ / p;

		// calculate the real world step vector we have to add for each x (parallel to camera plane)
		// adding step by step avoids multiplications with a weight in the inner loop
		float floorStepX = rowDistance * (rayDirX1 - rayDirX0) / game->params->r[0];
		float floorStepY = rowDistance * (rayDirY1 - rayDirY0) / game->params->r[0];

		// real world coordinates of the leftmost column. This will be updated as we step to the right.
		float floorX = game->player.x / game->map.block_size * 0.65 + rowDistance * rayDirX0;
		float floorY = game->player.y / game->map.block_size * 0.65 + rowDistance * rayDirY0;
		
		for(int x = 0; x < game->params->r[0]; x++)
		{
			// the cell coord is simply got from the integer parts of floorX and floorY
			int cellX = (int)(floorX);
			int cellY = (int)(floorY);

			// get the texture coordinate from the fractional part
			int tx = (int)(texture.width * (floorX - cellX)) & (texture.width - 1);
			int ty = (int)(texture.height * (floorY - cellY)) & (texture.width - 1);

			floorX += floorStepX;
			floorY += floorStepY;
			
			// floor
			// color = texture[floorTexture][texture.width * ty + tx];
			// color = (color >> 1) & 8355711; // make a bit darker
			// buffer[y][x] = color;
			
			// texture.frame = game->frame.img_addr + \
			// 	((int)y * game->frame.size_line + \
			// 	(int)x * (game->frame.bpp / 8));
			// texture.tex_image = texture.img.img_addr + \
			// 	((int)ty * texture.img.size_line + \
			// 	(int)tx * (texture.img.bpp / 8));
			// *(unsigned int*)texture.frame = *(unsigned int*)texture.tex_image;
			
			((int *)(game->frame.img_addr))[y * game->params->r[0] + x] = \
				((int *)(texture.img.img_addr))[ty * texture.width + tx];

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
	//set_floor1(game, ray);
}
