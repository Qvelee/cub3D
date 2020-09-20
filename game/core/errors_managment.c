/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_managment.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 16:59:36 by nelisabe          #+#    #+#             */
/*   Updated: 2020/09/20 17:00:23 by nelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		free_structer(t_pars *params)
{
	int index;

	index = -1;
	free(params->no);
	free(params->so);
	free(params->we);
	free(params->ea);
	free(params->s);
	while (params->map[++index])
		free(params->map[index]);
	free(params->map);
	return (0);
}
