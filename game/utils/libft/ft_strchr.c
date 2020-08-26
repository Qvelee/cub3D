/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 13:58:40 by nelisabe          #+#    #+#             */
/*   Updated: 2020/05/20 14:50:03 by nelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str_in, int symbol)
{
	size_t	index;
	char	*str;

	str = (char *)str_in;
	index = 0;
	while (str[index] != '\0')
		if (str[index++] == (unsigned char)symbol)
			return (&str[index - 1]);
	if ((unsigned char)symbol == '\0')
		return (&str[index]);
	return (NULL);
}
