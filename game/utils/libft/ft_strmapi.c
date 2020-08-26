/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 22:34:23 by nelisabe          #+#    #+#             */
/*   Updated: 2020/05/19 22:47:02 by nelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *str, char (*f)(unsigned int, char))
{
	long index;
	char *result;

	index = -1;
	if (!(str && f))
		return (NULL);
	result = (char*)malloc(sizeof(char) * ft_strlen(str) + 1);
	if (!(result))
		return (NULL);
	while (str[++index] != '\0')
	{
		result[index] = str[index];
		result[index] = f(index, result[index]);
	}
	result[index] = '\0';
	return (result);
}
