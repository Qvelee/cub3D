/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 10:00:20 by nelisabe          #+#    #+#             */
/*   Updated: 2020/05/20 14:37:46 by nelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t num)
{
	size_t			index;
	unsigned char	*cp_dest;
	unsigned char	*cp_src;

	if (!(dest || src))
		return (NULL);
	index = 0;
	cp_dest = (unsigned char *)dest;
	cp_src = (unsigned char *)src;
	if (cp_dest > cp_src)
	{
		index = num;
		while (index > 0)
		{
			cp_dest[index - 1] = cp_src[index - 1];
			index--;
		}
	}
	else
		while (index < num)
		{
			cp_dest[index] = cp_src[index];
			index++;
		}
	return (cp_dest);
}
