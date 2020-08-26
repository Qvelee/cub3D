/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 20:24:08 by nelisabe          #+#    #+#             */
/*   Updated: 2020/05/24 14:26:21 by nelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t index;
	size_t sindex;
	size_t dst_length;
	size_t src_length;

	sindex = 0;
	dst_length = 0;
	src_length = ft_strlen(src);
	while (dst[dst_length] != '\0')
	{
		if (dst_length == size)
			return (dst_length + src_length);
		dst_length++;
	}
	index = dst_length;
	while (index + 1 < size && src[sindex] != '\0')
		dst[index++] = src[sindex++];
	dst[index] = '\0';
	return (dst_length + src_length);
}
