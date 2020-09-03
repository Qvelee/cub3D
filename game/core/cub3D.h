/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 14:04:44 by nelisabe          #+#    #+#             */
/*   Updated: 2020/09/03 19:31:23 by nelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include "../utils/libft/libft.h"
#include "../utils/get_next_line/get_next_line.h"
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>

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

int 	cub3d(char *path);
int		parser(char *path, t_pars *params);
int		free_struct(t_pars *params);

#endif