/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 16:46:56 by nelisabe          #+#    #+#             */
/*   Updated: 2020/05/20 15:13:57 by nelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t num)
{
	size_t			index;
	int				code_s1;
	int				code_s2;
	unsigned char	*cp_s1;
	unsigned char	*cp_s2;

	cp_s1 = (unsigned char *)s1;
	cp_s2 = (unsigned char *)s2;
	code_s1 = 0;
	code_s2 = 0;
	index = 0;
	if (num == 0)
		return (0);
	while (index < num)
	{
		code_s1 = cp_s1[index];
		code_s2 = cp_s2[index];
		if (code_s1 != code_s2)
			break ;
		if (cp_s1[index] == '\0' || cp_s2[index] == '\0')
			break ;
		index++;
	}
	return (code_s1 - code_s2);
}
