/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 21:28:47 by nelisabe          #+#    #+#             */
/*   Updated: 2020/05/20 22:21:20 by nelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	free_mem(char **result)
{
	size_t index;

	index = 0;
	while (result[index])
		free(result[index++]);
	free(result);
}

static	char	*allocate_str(const char *str, size_t begin, size_t end)
{
	char	*temp;
	size_t	index;

	index = 0;
	if (!(temp = (char*)malloc(sizeof(char) * (end - begin) + 1)))
		return (NULL);
	while (begin < end)
		temp[index++] = str[begin++];
	temp[index] = '\0';
	return (temp);
}

static	char	**put_strings(char **result, const char *str, char symbol)
{
	size_t index;
	size_t sindex;
	size_t res_index;

	index = 0;
	res_index = 0;
	while (str[index] != '\0')
	{
		sindex = index;
		if (str[sindex] != symbol)
		{
			while (str[sindex] != symbol && str[sindex] != '\0')
				sindex++;
			if (!(result[res_index++] = allocate_str(str, index, sindex)))
			{
				free_mem(result);
				return (NULL);
			}
		}
		index = sindex + 1;
		if (str[sindex] == '\0')
			break ;
	}
	result[res_index] = NULL;
	return (result);
}

static	size_t	num_of_words(char const *str, char symbol)
{
	size_t index;
	size_t number;

	index = 0;
	number = 0;
	while (str[index] != '\0')
	{
		if (str[index] != symbol)
		{
			while (str[index] != symbol && str[index] != '\0')
				index++;
			number++;
		}
		else
			while (str[index] == symbol)
				index++;
	}
	return (number);
}

char			**ft_split(char const *str, char symbol)
{
	char	**result;
	size_t	num_words;

	if (!(str))
		return (NULL);
	num_words = num_of_words(str, symbol);
	if (!(result = (char**)malloc(sizeof(char*) * num_words + 1)))
		return (NULL);
	if (!(result = put_strings(result, str, symbol)))
		return (NULL);
	return (result);
}
