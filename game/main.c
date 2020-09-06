/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 21:07:13 by nelisabe          #+#    #+#             */
/*   Updated: 2020/09/06 19:07:16 by nelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/cub3d.h"

int		main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putendl_fd("cub3D: Wrong number of arguments", 1);
		return (0);
	}
	cub3d(argv[1]);
	return (0);
}
