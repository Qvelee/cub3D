/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 14:24:55 by nelisabe          #+#    #+#             */
/*   Updated: 2020/09/02 21:13:28 by nelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

//add correct input check (no simbols, no alnums)
//add mallocs protect and error managment

static int	rfc_pars(int type, char *component, t_pars *params)
{
	if (type == 0)
	{
		params->r[0] = ft_atoi(component);
		params->r[1] = ft_atoi(ft_strchr(component, ' '));
		return (1);
	}
	else if (type == 6)
	{
		params->f[0] = ft_atoi(component);
		params->f[1] = ft_atoi(ft_strchr(component, ',') + 1);
		params->f[2] = ft_atoi(ft_strrchr(component, ',') + 1);
		return (1);
	}
	else
	{
		params->c[0] = ft_atoi(component);
		params->c[1] = ft_atoi(ft_strchr(component, ',') + 1);
		params->c[2] = ft_atoi(ft_strrchr(component, ',') + 1);
		return (1);
	}
	return (0);
}

static int	nswes_pars(int type, char *component, t_pars *params)
{
	if (type == 1)
	{
		params->no = ft_strdup(component);
	}
	else if (type == 2)
	{
		params->so = ft_strdup(component);
	}
	else if (type == 3)
	{
		params->we = ft_strdup(component);
	}
	else if (type == 4)
	{
		params->ea = ft_strdup(component);
	}
	else if (type == 5)
	{
		params->s = ft_strdup(component);
	}
	return (1);
}

int		upd_pars(int type, char *component, t_pars *params)
{
	if (type == 0 || type == 6 || type == 7)
		return (rfc_pars(type, component, params));
	else
		return (nswes_pars(type, component, params));
	return (0);
}