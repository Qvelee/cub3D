/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 19:05:07 by nelisabe          #+#    #+#             */
/*   Updated: 2020/09/13 14:13:15 by nelisabe         ###   ########.fr       */
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

typedef	struct	s_player
{
	t_img	pl_img;
	int		x;
	int		y;
}				t_player;

typedef	struct	s_core
{
	t_pars		*params;
	void		*mlx;
	void		*window;
	t_img		map;
	t_player	player;
}				t_core;

int				cub3d(char *path);
int				parser(char *path, t_pars *params);
int				init_lib(t_pars *params);

#endif
