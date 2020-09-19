/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 19:05:07 by nelisabe          #+#    #+#             */
/*   Updated: 2020/09/19 23:30:48 by nelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../utils/libft/libft.h"
# include "../utils/get_next_line/get_next_line.h"
# include "../../minilibx/mlx.h"
# include <math.h>
# include <fcntl.h>
# include <string.h>
# include <stdio.h>
# include <errno.h>

typedef	struct	s_pars
{
	int		r[2];
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*s;
	int		f[3];
	int		c[3];
	char	**map;
}				t_pars;

typedef	struct	s_img
{
	void	*image;
	char	*img_addr;
	int		bpp;
	int		size_line;
	int		endian;
}				t_img;

typedef	struct	s_buttons
{
	int a;
	int s;
	int d;
	int w;
	int left;
	int right;
}				t_buttons;

typedef	struct	s_ray_cast
{
	double	current_angle;
	int		num_rays;
	double	x;
	double	y;
	double	dx;
	double	dy;
	double	xm;
	double	ym;
	double	depth;
	double	depth_v;
	double	depth_h;
}				t_ray_cast;

typedef	struct	s_map
{
	int	map_lines;
	int	map_colunms;
	int	block_size;
}				t_map;

typedef	struct	s_player
{
	double	angle;
	double	speed;
	double	angle_speed;
	double	fov;
	int		num_rays;
	double	delta_angle;
	double	x;
	double	y;
}				t_player;

typedef	struct	s_core
{
	t_pars		*params;
	void		*mlx;
	void		*window;
	t_img		frame;
	t_buttons	button;
	t_map		map;
	t_player	player;
}				t_core;

int				cub3d(char *path);
int				parser(char *path, t_pars *params);
int				engine(t_pars *pars);
void			pixel_put(t_img image, int x, int y, int color);
void			draw_circle(t_core *game, int x0, int y0, int radius);
void			draw_line(t_core *game, int x1, int y1, int x2, int y2);
void			draw_block(t_core *game, int x, int y, int color);
int				map(t_core *game);
int				player(t_core *game);

#endif
