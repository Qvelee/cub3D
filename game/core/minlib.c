/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minlib.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 14:02:04 by nelisabe          #+#    #+#             */
/*   Updated: 2020/09/19 16:49:05 by nelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	pixel_put(t_img image, int x, int y, int color)
{
	char *dst;
	
	dst = image.img_addr + (y * image.size_line + x * (image.bpp / 8));
	*(unsigned int*)dst = color;
}

int		draw_block(t_img image, int *x, int y, int color)
{
	int xc;
	int yc;

	yc = y;
	while (++yc < y + 50)
	{
		xc = *x - 1;
		while (++xc < (*x) + 50)
			pixel_put(image, xc, yc, color);
	}
	(*x) += 50;
	return (0);
}

int		draw_map(t_core *game)
{
	int index;
	int sindex;
	int y;
	int x;

	index = -1;
	x = 99;
	y = 99;
	game->map.image = mlx_new_image(game->mlx, game->params->r[0], game->params->r[1]);
	game->map.img_addr = mlx_get_data_addr(game->map.image, &game->map.bpp, &game->map.size_line, &game->map.endian);
	while (game->params->map[++index])
	{
		sindex = -1;
		while (game->params->map[index][++sindex] != '\0')
			if (game->params->map[index][sindex] == '1')
				draw_block(game->map, &x, y, 0xBBBBBB);
			else if (game->params->map[index][sindex] == ' ')
				draw_block(game->map, &x, y, 0x002200);
			else //if (params->map[index][sindex] == '0')
				draw_block(game->map, &x, y, 0xEEEEEE);
		y += 49;
		x = 99;
	}
	mlx_put_image_to_window(game->mlx, game->window, game->map.image, 0, 0);
	mlx_do_sync(game->mlx);
	return (0);
}

void	get_player_pos(t_core *game)
{
	int index;
	int sindex;

	game->player.x = 99;
	game->player.y = 99;
	index = -1;
	while (game->params->map[++index])
	{
		sindex = -1;
		while (game->params->map[index][++sindex] != '\0')
		{
			if (game->params->map[index][sindex] == 'N')
				return ;
			game->player.x += 50;
		}
		game->player.x = 99;
		game->player.y += 50;
	}
	game->player.angle = 0;
}

void	draw_player(t_core *game)
{
	int x;

	x = 0;
	game->player.pl_img.image = mlx_new_image(game->mlx, 50, 50);
	game->player.pl_img.img_addr = mlx_get_data_addr(game->player.pl_img.image, &game->player.pl_img.bpp, &game->player.pl_img.size_line, &game->player.pl_img.endian);
	draw_block(game->player.pl_img, &x, 0, 0x33FFFF);
	mlx_put_image_to_window(game->mlx, game->window, game->player.pl_img.image, game->player.x, game->player.y);
	mlx_do_sync(game->mlx);
}

void	draw_line(t_core *game, int x1, int y1, int x2, int y2)
{
	const int deltaX = abs(x2 - x1);
    const int deltaY = abs(y2 - y1);
    const int signX = x1 < x2 ? 1 : -1;
    const int signY = y1 < y2 ? 1 : -1;

	int error = deltaX - deltaY;
	mlx_pixel_put(game->mlx, game->window, x2, y2, 0x0033FF);
    //pixel_put(game->player.pl_img, x2, y2, 0x0033FF);
    while(x1 != x2 || y1 != y2) 
   {
		mlx_pixel_put(game->mlx, game->window, x1, y1, 0x0033FF);
		//pixel_put(game->player.pl_img, x1, y1, 0x0033FF);
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

int		key_hook(int keycode, t_core *game)
{
	if (keycode == 0x0061) //a
	{
		mlx_destroy_image(game->mlx, game->map.image);
		mlx_destroy_image(game->mlx, game->player.pl_img.image);
		game->player.x -= 10;
		draw_map(game);
		draw_player(game);
	}
	if (keycode == 0x0077) //w
	{
		mlx_destroy_image(game->mlx, game->map.image);
		mlx_destroy_image(game->mlx, game->player.pl_img.image);
		game->player.y -= 10;
		draw_map(game);
		draw_player(game);
	}
	if (keycode == 0x0064) //d
	{
		mlx_destroy_image(game->mlx, game->map.image);
		mlx_destroy_image(game->mlx, game->player.pl_img.image);
		game->player.x += 10;
		draw_map(game);
		draw_player(game);
	}
	if (keycode == 0x0073) //s
	{
		mlx_destroy_image(game->mlx, game->map.image);
		mlx_destroy_image(game->mlx, game->player.pl_img.image);
		game->player.y += 10;
		draw_map(game);
		draw_player(game);
	}
	if (keycode == 0xff1b) //esc
	{
		mlx_destroy_image(game->mlx, game->map.image);
		mlx_destroy_image(game->mlx, game->player.pl_img.image);
		mlx_clear_window(game->mlx, game->window);
		mlx_destroy_window(game->mlx, game->window);
		exit(0);
	}
	if (keycode == 0xff51) //left
	{
		game->player.angle -= 0.02;
		draw_line(game, game->player.x, game->player.y, game->player.x + game->params->r[0] * cos(game->player.angle), game->player.y + game->params->r[1] * sin(game->player.angle));
	}
	// if (keycode == 0xff52) // up
	// {
	// 	draw_line();
	// }
	if (keycode == 0xff53) //right
	{
		game->player.angle += 0.02;
		draw_line(game, game->player.x, game->player.y, game->player.x + game->params->r[0] * cos(game->player.angle), game->player.y + game->params->r[1] * sin(game->player.angle));
	}
	// if (keycode == 0xff54) //down
	// {
	// 	draw_line();
	// }
	return (0);
}

int		init_lib(t_pars *pars)
{
	t_core game;
	
	game.params = pars;
	game.mlx = mlx_init();
	game.window = mlx_new_window(game.mlx, game.params->r[0], game.params->r[1], "cub3D");
	draw_map(&game);
	get_player_pos(&game);
	draw_player(&game);
	draw_line(&game, game.player.x, game.player.y, game.player.x + game.params->r[0], game.player.y + game.params->r[1]);
	mlx_hook(game.window, 2, 1, key_hook, &game);
	mlx_loop(game.mlx);
	return (0);
}