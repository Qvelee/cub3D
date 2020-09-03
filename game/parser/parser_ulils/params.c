/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 14:24:55 by nelisabe          #+#    #+#             */
/*   Updated: 2020/09/03 20:43:00 by nelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

//add correct input check (no simbols, no alnums)
//add mallocs protect and error managment

static int	check_color_par_correct(char *component)
{
	int index;
	int point;

	index = -1;
	point = 0;
	while (component[++index] != '\0')
	{
		if (!ft_isdigit(component[index]))
		{
			if (component[index] == ',')
			{
				if (point < 2)
					point++;
				else
					return (1);
			}
			else
				return (1);
		}
	}
	return (point != 2);
}

static int	check_r_par_correct(char *component)
{
	int	index;
	int space;

	index = -1;
	space = 0;
	while (component[++index] != '\0')
	{
		if (!ft_isdigit(component[index]))
		{
			if (component[index] == ' ')
			{
				if (space == 0)
					space = 1;
				else
					return (1);
			}
			else
				return (1);
		}
	}
	return (space != 1);
}

static int	rfc_pars(int type, char *component, t_pars *params)
{
	if (type == 0)
	{
		if (check_r_par_correct(component))
			return (error_r_par_not_correct(component));
		params->r[0] = ft_atoi(component);
		params->r[1] = ft_atoi(ft_strchr(component, ' '));
	}
	if (type == 6)
	{
		if (check_color_par_correct(component))
			return (error_color_par_not_correct(component, params));
		params->f[0] = ft_atoi(component);
		params->f[1] = ft_atoi(ft_strchr(component, ',') + 1);
		params->f[2] = ft_atoi(ft_strrchr(component, ',') + 1);
	}
	if (type == 7)
	{
		if (check_color_par_correct(component))
			return (error_color_par_not_correct(component, params));
		params->c[0] = ft_atoi(component);
		params->c[1] = ft_atoi(ft_strchr(component, ',') + 1);
		params->c[2] = ft_atoi(ft_strrchr(component, ',') + 1);
	}
	return (1);
}

static int	nswes_pars(int type, char *component, t_pars *params)
{
	if (type == 1)
		if (!(params->no = ft_strdup(component)))
			return (error_nswes_malloc(params));
	if (type == 2)
		if (!(params->so = ft_strdup(component)))
			return (error_nswes_malloc(params));
	if (type == 3)
		if (!(params->we = ft_strdup(component)))
			return (error_nswes_malloc(params));
	if (type == 4)
		if (!(params->ea = ft_strdup(component)))
			return (error_nswes_malloc(params));
	if (type == 5)
		if (!(params->s = ft_strdup(component)))
			return (error_nswes_malloc(params));
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