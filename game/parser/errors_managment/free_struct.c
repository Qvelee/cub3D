/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 18:32:45 by nelisabe          #+#    #+#             */
/*   Updated: 2020/09/06 19:16:20 by nelisabe         ###   ########.fr       */
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
