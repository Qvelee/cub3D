/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 13:51:15 by nelisabe          #+#    #+#             */
/*   Updated: 2020/08/26 16:43:01 by nelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_m(const char *str)
{
	unsigned long int index;

	index = 0;
	while (str[index] != '\0')
		index++;
	return (index);
}

char	*ft_strchr_m(const char *str_in, int symbol)
{
	size_t	index;
	char	*str;

	str = (char *)str_in;
	index = 0;
	while (str[index] != '\0')
		if (str[index++] == (unsigned char)symbol)
			return (&str[index - 1]);
	if ((unsigned char)symbol == '\0')
		return (&str[index]);
	return (NULL);
}

char	*ft_strdup_m(const char *str)
{
	char	*pointer;
	long	index;

	index = 0;
	while (str[index] != '\0')
		index++;
	if (!(pointer = (char*)malloc(sizeof(char) * (index + 1))))
		return (NULL);
	index = -1;
	while (str[++index] != '\0')
		pointer[index] = str[index];
	pointer[index] = str[index];
	return (pointer);
}

size_t	ft_strcpy_m(char *dst, const char *src)
{
	size_t index;

	index = 0;
	if (src)
	{
		while (src[index] != '\0')
		{
			dst[index] = src[index];
			index++;
		}
		dst[index] = '\0';
	}
	return (index);
}

char	*ft_strjoin_m(char *str1, char *str2)
{
	unsigned long	len_joinstr;
	char			*joinstr;
	int				index;
	int				sindex;

	index = 0;
	sindex = 0;
	if (!(str1 && str2))
		return (NULL);
	len_joinstr = ft_strlen_m(str1) + ft_strlen_m(str2);
	if (!(joinstr = (char*)malloc(sizeof(char) * (len_joinstr + 1))))
		return (NULL);
	while (str1[index] != '\0')
		joinstr[sindex++] = str1[index++];
	index = 0;
	while (str2[index] != '\0')
		joinstr[sindex++] = str2[index++];
	joinstr[sindex] = '\0';
	return (joinstr);
}
