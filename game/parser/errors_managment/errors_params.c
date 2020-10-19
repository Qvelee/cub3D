/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 14:42:23 by nelisabe          #+#    #+#             */
/*   Updated: 2020/10/19 17:31:07 by nelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

int		check_color_valid(t_pars *params, int type)
{
	if (type == 6 && \
		(params->f[0] > 255 || params->f[1] > 255 || params->f[2] > 255 ||
			params->f[0] < 0 || params->f[1] < 0 || params->f[2] < 0))
	{
		free_struct(params);
		ft_putendl_fd("Error", 1);
		ft_putendl_fd("cub3D: Floor color not valid", 1);
		return (1);
	}
	if (type == 7 && \
		(params->c[0] > 255 || params->c[1] > 255 || params->c[2] > 255 || 
			params->c[0] < 0 || params->c[1] < 0 || params->c[2] < 0))
	{
		free_struct(params);
		ft_putendl_fd("Error", 1);
		ft_putendl_fd("cub3D: Ceiling color not valid", 1);
		return (1);
	}
	return (0);
}

int		error_color_par_not_correct(char *line, t_pars *params)
{
	free_struct(params);
	ft_putendl_fd("Error", 1);
	ft_putstr_fd("cub3D: This line \"", 1);
	ft_putstr_fd(line, 1);
	ft_putendl_fd("\" is not correct", 1);
	return (0);
}

int		error_r_par_not_correct(char *line)
{
	ft_putendl_fd("Error", 1);
	ft_putstr_fd("cub3D: This line \"", 1);
	ft_putstr_fd(line, 1);
	ft_putendl_fd("\" is not correct", 1);
	return (0);
}

int		error_nswes_malloc(t_pars *params, int error)
{
	free_struct(params);
	ft_putendl_fd("Error", 1);
	if (!error)
		ft_putendl_fd("cub3D: Memory allocation fail", 1);
	else
		ft_putendl_fd("cub3D: Too many parameters", 1);
	return (0);
}
