/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 15:45:46 by nelisabe          #+#    #+#             */
/*   Updated: 2020/10/21 19:38:24 by nelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char				*substr;
	unsigned long		index;

	if (!(str))
		return (NULL);
	if (!(len) || start > ft_strlen(str))
		return (ft_strdup(""));
	substr = ft_calloc(len + 1, 1);
	if (!(substr))
		return (NULL);
	index = 0;
	while (index < len && str[index] != '\0')
		substr[index++] = str[start++];
	substr[index] = '\0';
	return (substr);
}
