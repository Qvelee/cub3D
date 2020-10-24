/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 21:07:13 by nelisabe          #+#    #+#             */
/*   Updated: 2020/10/24 13:59:40 by nelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/cub3d.h"

int		main(int argc, char **argv)
{
	if (argc < 2 || argc > 3)
	{
		ft_putendl_fd("Error", 1);
		ft_putendl_fd("cub3D: Wrong number of arguments", 1);
		return (0);
	}
	if (argc == 2)
		cub3d(argv[1], NULL);
	if (argc == 3)
		cub3d(argv[1], argv[2]);
	return (0);
}
