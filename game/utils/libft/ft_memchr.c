/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 12:06:50 by nelisabe          #+#    #+#             */
/*   Updated: 2020/05/20 14:36:57 by nelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *src, int symbol, size_t num)
{
	size_t			index;
	unsigned char	*cp_src;

	index = 0;
	cp_src = (unsigned char *)src;
	while (index < num)
		if (cp_src[index++] == (unsigned char)symbol)
			return (&cp_src[index - 1]);
	return (NULL);
}
