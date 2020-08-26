/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 17:45:23 by nelisabe          #+#    #+#             */
/*   Updated: 2020/05/20 14:37:08 by nelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int symbol, size_t num)
{
	size_t			index;
	unsigned char	*cp_dest;
	unsigned char	*cp_src;

	cp_dest = (unsigned char *)dest;
	cp_src = (unsigned char *)src;
	index = 0;
	while (index < num)
	{
		cp_dest[index] = cp_src[index];
		if (cp_src[index] == (unsigned char)symbol)
			return (&cp_dest[index + 1]);
		index++;
	}
	return (NULL);
}
