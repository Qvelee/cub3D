/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 02:40:26 by nelisabe          #+#    #+#             */
/*   Updated: 2020/05/17 14:12:45 by nelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*pointer;
	long	index;

	index = 0;
	while (str[index] != '\0')
		index++;
	pointer = ft_calloc(index + 1, 1);
	if (!(pointer))
		return (NULL);
	index = -1;
	while (str[++index] != '\0')
		pointer[index] = str[index];
	pointer[index] = str[index];
	return (pointer);
}
