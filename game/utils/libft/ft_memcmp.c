/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 12:19:37 by nelisabe          #+#    #+#             */
/*   Updated: 2020/05/20 14:42:25 by nelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t num)
{
	size_t			index;
	unsigned char	*cp_s1;
	unsigned char	*cp_s2;

	index = 0;
	cp_s1 = (unsigned char *)s1;
	cp_s2 = (unsigned char *)s2;
	while (index < num)
	{
		if (cp_s1[index] != cp_s2[index])
			return (cp_s1[index] - cp_s2[index]);
		index++;
	}
	return (0);
}
