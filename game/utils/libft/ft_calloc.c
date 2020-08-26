/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 01:34:22 by nelisabe          #+#    #+#             */
/*   Updated: 2020/05/20 15:42:08 by nelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*pointer;

	pointer = (void*)malloc(nmemb * size);
	if (pointer)
	{
		ft_memset(pointer, 0, nmemb * size);
		return (pointer);
	}
	return (NULL);
}
