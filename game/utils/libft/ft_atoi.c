/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 17:19:36 by nelisabe          #+#    #+#             */
/*   Updated: 2020/05/20 15:16:00 by nelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	int result;
	int index;
	int minus;

	index = 0;
	result = 0;
	minus = 1;
	while (str[index] == ' ' || (str[index] <= '\r' && str[index] >= '\t'))
		index++;
	if (str[index] == '+' || str[index] == '-')
		if (str[index++] == '-')
			minus = -1;
	while (str[index] >= '0' && str[index] <= '9')
		result = result * 10 + (str[index++] - '0');
	return (result * minus);
}
