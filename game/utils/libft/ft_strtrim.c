/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 13:59:42 by nelisabe          #+#    #+#             */
/*   Updated: 2020/05/24 16:34:42 by nelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		in_set(char symbol, char const *set)
{
	long index;

	index = -1;
	while (set[++index] != '\0')
		if (symbol == set[index])
			return (1);
	return (0);
}

char			*ft_strtrim(char const *str, char const *set)
{
	long last_sym;

	if (!(str && set))
		return (NULL);
	while (*str != '\0')
		if (in_set(*str, set))
			str++;
		else
			break ;
	last_sym = ft_strlen(str) - 1;
	while (*str != '\0')
		if (in_set(*(str + last_sym), set))
			last_sym--;
		else
			break ;
	return (ft_substr(str, 0, last_sym + 1));
}
