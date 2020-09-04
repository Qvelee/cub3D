/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 14:02:27 by nelisabe          #+#    #+#             */
/*   Updated: 2020/09/04 20:18:56 by nelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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

static void print_struct(t_pars *params)
{
	int index;

	printf("resolution - %4d %4d\n", params->r[0], params->r[1]);
	printf("north - %20s\n", params->no);
	printf("south - %20s\n", params->so);
	printf("west  - %20s\n", params->we);
	printf("east  - %20s\n", params->ea);
	printf("floor - %d,%d,%d\n", params->f[0], params->f[1], params->f[2]);
	printf("ceiling - %d,%d,%d\n", params->c[0], params->c[1], params->c[2]);
	index = -1;
	while (params->map[++index])
		printf("%s\n", params->map[index]);
}

int 	cub3d(char *path)
{
	t_pars params;
	
	if (parser(path, &params))
		return (0);
	print_struct(&params);
	free_structer(&params);
	return (0);
}