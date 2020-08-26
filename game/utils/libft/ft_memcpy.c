/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 15:11:54 by nelisabe          #+#    #+#             */
/*   Updated: 2020/05/20 14:05:35 by nelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t num)
{
	size_t			index;
	unsigned char	*cp_dest;
	unsigned char	*cp_src;

	index = 0;
	if (!(dest || src))
		return (NULL);
	cp_dest = (unsigned char *)dest;
	cp_src = (unsigned char *)src;
	while (index < num)
	{
		cp_dest[index] = cp_src[index];
		index++;
	}
	return (cp_dest);
}
