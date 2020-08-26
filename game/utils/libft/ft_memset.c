/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 15:11:57 by nelisabe          #+#    #+#             */
/*   Updated: 2020/05/20 14:01:28 by nelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int sim, size_t num)
{
	size_t			index;
	unsigned char	*str;
	unsigned char	simbol;

	index = 0;
	str = (unsigned char *)ptr;
	simbol = (unsigned char)sim;
	while (index < num)
		str[index++] = simbol;
	return (str);
}
