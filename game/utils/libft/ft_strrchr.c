/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 14:20:46 by nelisabe          #+#    #+#             */
/*   Updated: 2020/05/20 17:42:42 by nelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str_in, int symbol)
{
	size_t	index;
	char	*str;
	char	*temp;

	index = 0;
	str = (char *)str_in;
	temp = NULL;
	while (str[index] != '\0')
		if (str[index++] == (unsigned char)symbol)
			temp = &str[index - 1];
	if ((unsigned char)symbol == '\0')
		temp = &str[index];
	return (temp);
}
