/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 18:32:45 by nelisabe          #+#    #+#             */
/*   Updated: 2020/10/12 14:22:52 by nelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

int		free_struct(t_pars *params)
{
	free(params->no);
	free(params->so);
	free(params->we);
	free(params->ea);
	free(params->s);
	return (0);
}

int		error_invalid_file(t_pars *params)
{
	if (!params->no || !params->so || !params->ea || !params->we || \
		!params->s || !params->map)
	{
		free_struct(params);
		ft_putendl_fd("Error", 1);
		ft_putendl_fd("cub3D: Invalid file", 1);
		return (1);
	}
	return (0);
}

int		error_open_file()
{
	ft_putendl_fd("Error", 1);
	perror("cub3D");
	return (0);
}

int		error_wrong_filename()
{
	ft_putendl_fd("Error", 1);
	ft_putendl_fd("cub3D: File extension not .cub", 1);
	return (0);
}
