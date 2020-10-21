/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 14:32:37 by nelisabe          #+#    #+#             */
/*   Updated: 2020/10/21 19:21:09 by nelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

int		error_in_params(t_pars *params)
{
	if (params->r[0] == 0 || params->r[1] == 0 || \
		params->no == NULL || params->so == NULL || params->we == NULL || \
		params->ea == NULL || params->s == NULL || \
		params->f[0] == 666 || params->c[0] == 666)
	{
		free_struct(params);
		ft_putendl_fd("Error", 1);
		ft_putendl_fd("cub3D: Not all parameters", 1);
		return (1);
	}
	return (0);
}

int		error_invalid_params(t_pars *params)
{
	free_struct(params);
	ft_putendl_fd("Error", 1);
	ft_putendl_fd("cub3D: Invalid parameters", 1);
	return (0);
}

int		error_get_map(char **line, int fd, int error)
{
	int temp;

	if (error == -1)
	{
		free(*line);
		return (0);
	}
	free(*line);
	while ((temp = get_next_line(fd, line)))
	{
		if (temp == -1)
			break ;
		free(*line);
	}
	free(*line);
	close(fd);
	return (0);
}

int		error_get_pars(char **line, int fd)
{
	int temp;

	free(*line);
	while ((temp = get_next_line(fd, line)))
	{
		if (temp == -1)
			break ;
		free(*line);
	}
	free(*line);
	close(fd);
	return (0);
}

int		error_read_file_pars(int fd, t_pars *params)
{
	close(fd);
	free_struct(params);
	ft_putendl_fd("Error", 1);
	ft_putendl_fd("cub3D: Error while reading from file", 1);
	return (0);
}
