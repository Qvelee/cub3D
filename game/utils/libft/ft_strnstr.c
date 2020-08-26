/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 14:32:54 by nelisabe          #+#    #+#             */
/*   Updated: 2020/05/20 15:09:36 by nelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *lit, size_t len)
{
	size_t	i;
	size_t	s;
	char	*cbig;
	char	*clit;

	cbig = (char *)big;
	clit = (char *)lit;
	i = 0;
	if (len && (cbig[0] && clit[0] != '\0'))
		while (cbig[i] != '\0' && i < len)
		{
			s = 0;
			if (cbig[i] == clit[s])
			{
				while (clit[s] == cbig[i + s] && clit[s] != '\0' && i + s < len)
					s++;
				if (clit[s] == '\0')
					return (&cbig[i]);
			}
			i++;
		}
	if (clit[0] == '\0')
		return (cbig);
	return (NULL);
}
