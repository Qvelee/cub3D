/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 18:30:55 by nelisabe          #+#    #+#             */
/*   Updated: 2020/05/22 17:48:44 by nelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *str1, char const *str2)
{
	unsigned long	len_joinstr;
	char			*joinstr;

	if (!(str1 && str2))
		return (NULL);
	len_joinstr = ft_strlen(str1) + ft_strlen(str2);
	joinstr = ft_calloc(len_joinstr + 1, 1);
	if (!(joinstr))
		return (NULL);
	ft_strlcpy(joinstr, str1, len_joinstr + 1);
	ft_strlcat(joinstr, str2, len_joinstr + 1);
	return (joinstr);
}
