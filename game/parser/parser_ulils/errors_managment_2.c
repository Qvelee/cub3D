/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_managment_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 20:16:15 by nelisabe          #+#    #+#             */
/*   Updated: 2020/09/03 20:38:48 by nelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

int		error_color_par_not_correct(char *line, t_pars *params)
{
	free_struct(params);
	ft_putstr_fd("cub3D: This line \"", 1);
	ft_putstr_fd(line, 1);
	ft_putendl_fd("\" is not correct", 1);
	return (0);
}

int		error_r_par_not_correct(char *line)
{
	ft_putstr_fd("cub3D: This line \"", 1);
	ft_putstr_fd(line, 1);
	ft_putendl_fd("\" is not correct", 1);
	return (0);
}