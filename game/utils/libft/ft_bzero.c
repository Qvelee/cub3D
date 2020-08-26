/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 22:08:33 by nelisabe          #+#    #+#             */
/*   Updated: 2020/05/20 14:01:20 by nelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *ptr, size_t number)
{
	size_t			index;
	unsigned char	*str;

	index = 0;
	str = (unsigned char *)ptr;
	while (index < number)
		str[index++] = 0;
	return ;
}
