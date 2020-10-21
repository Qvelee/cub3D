/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 19:32:41 by nelisabe          #+#    #+#             */
/*   Updated: 2020/10/21 21:51:07 by nelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int		digits(int num)
{
	int result;

	result = 0;
	if (num < 0)
	{
		result = 1;
		num *= -1;
	}
	if (!num)
		result = 1;
	while (num)
	{
		num /= 10;
		result++;
	}
	return (result);
}

char	*ft_itoa(int num)
{
	char	*str;
	int		index;

	index = digits(num);
	if (!(str = (char*)malloc(sizeof(char) * (index + 1))) || !str)
		return (NULL);
	ft_bzero(str, index + 1);
	str[index--] = '\0';
	if (num < 0)
	{
		str[0] = '-';
		num *= -1;
	}
	while (index >= 0 && str[index] != '-')
	{
		str[index--] = num % 10 + '0';
		num /= 10;
	}
	return (str);
}
