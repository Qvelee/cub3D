/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_managment.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 18:25:21 by nelisabe          #+#    #+#             */
/*   Updated: 2020/09/04 15:28:45 by nelisabe         ###   ########.fr       */
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

int		error_invalid_params(t_pars *params)
{
	free_struct(params);
	ft_putendl_fd("cub3D: Invalid parameters", 1);
	return (0);
}

int		error_read_file_pars(int fd, t_pars *params)
{
	close(fd);
	free_struct(params);
	ft_putendl_fd("cub3D: Error while reading from file", 1);
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

int		error_nswes_malloc(t_pars *params)
{
	free_struct(params);
	ft_putendl_fd("cub3D: Memory allocation fail", 1);
	return (0);
}