/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 14:24:55 by nelisabe          #+#    #+#             */
/*   Updated: 2020/10/21 19:23:35 by nelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

static int	check_color_par_correct(char *component)
{
	int index;
	int point;
	int digits;

	index = -1;
	point = 0;
	digits = 0;
	while (component[++index] != '\0')
	{
		if (ft_isdigit(component[index]))
		{
			while (ft_isdigit(component[index]))
				index++;
			digits++;
		}
		if (component[index] == ',')
			point++;
		if (component[index] != ' ' && component[index] != '\0' && \
			component[index] != ',')
			return (1);
		if (component[index] == '\0')
			break ;
	}
	return (digits != 3 || point != 2);
}

static int	check_r_par_correct(char *component)
{
	int	index;
	int	digits;

	index = -1;
	digits = 0;
	while (component[++index] != '\0')
	{
		if (ft_isdigit(component[index]))
		{
			while (ft_isdigit(component[index]))
				index++;
			digits++;
		}
		if (component[index] != ' ' && component[index] != '\0')
			return (1);
		if (component[index] == '\0')
			break ;
	}
	return (digits != 2);
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
		if (check_color_par_correct(component) || params->f[0] != 666)
			return (error_color_par_not_correct(component, params));
		params->f[0] = ft_atoi(component);
		params->f[1] = ft_atoi(ft_strchr(component, ',') + 1);
		params->f[2] = ft_atoi(ft_strrchr(component, ',') + 1);
	}
	if (type == 7)
	{
		if (check_color_par_correct(component) || params->c[0] != 666)
			return (error_color_par_not_correct(component, params));
		params->c[0] = ft_atoi(component);
		params->c[1] = ft_atoi(ft_strchr(component, ',') + 1);
		params->c[2] = ft_atoi(ft_strrchr(component, ',') + 1);
	}
	return (1);
}

static int	nswes_pars(int type, char *component, t_pars *params)
{
	void *error;

	error = NULL;
	if (type == 1 && !(error = params->no))
		if (!(params->no = ft_strdup(component)))
			return (error_nswes_malloc(params, 0));
	if (type == 2 && !(error = params->so))
		if (!(params->so = ft_strdup(component)))
			return (error_nswes_malloc(params, 0));
	if (type == 3 && !(error = params->we))
		if (!(params->we = ft_strdup(component)))
			return (error_nswes_malloc(params, 0));
	if (type == 4 && !(error = params->ea))
		if (!(params->ea = ft_strdup(component)))
			return (error_nswes_malloc(params, 0));
	if (type == 5 && !(error = params->s))
		if (!(params->s = ft_strdup(component)))
			return (error_nswes_malloc(params, 0));
	if (error)
		return (error_nswes_malloc(params, 1));
	return (1);
}

int			upd_pars(int type, char *component, t_pars *params)
{
	static int	resolution;
	int			temp;

	if (type == 0 || type == 6 || type == 7)
	{
		if (type == 0)
		{
			if (!resolution)
				resolution = 1;
			else
				return (error_nswes_malloc(params, 1));
		}
		if ((temp = rfc_pars(type, component, params)))
		{
			if (type == 6 || type == 7)
				return (!check_color_valid(params, type));
			return (1);
		}
		else
			return (0);
	}
	else
		return (nswes_pars(type, component, params));
}
