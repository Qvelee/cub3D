/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 19:22:50 by nelisabe          #+#    #+#             */
/*   Updated: 2020/09/20 16:53:10 by nelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	int		free_structer(t_pars *params)
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

int				cub3d(char *path)
{
	t_pars params;

	if (parser(path, &params))
		return (0);
	//if last line not space map error why?
	handler(&params);
	free_structer(&params);
	return (0);
}
