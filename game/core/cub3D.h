/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 14:04:44 by nelisabe          #+#    #+#             */
/*   Updated: 2020/09/01 16:19:40 by nelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include "../utils/libft/libft.h"
#include "../utils/get_next_line/get_next_line.h"
#include <fcntl.h>
#include <string.h>
#include <stdio.h>

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

typedef	struct	s_map
{
	void			*content;
	struct s_map	*next;
}				t_map;

int 	cub3d(char *path);
int		parser(char *path, t_pars *params);
int		map_solve(int fd, char *last_line, t_pars *params);

#endif