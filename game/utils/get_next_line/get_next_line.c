/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 13:51:02 by nelisabe          #+#    #+#             */
/*   Updated: 2020/07/07 11:02:15 by nelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	swap_mem(char **line, char *temp)
{
	char *swap;

	swap = *line;
	if (!(*line = ft_strjoin(*line, temp)))
	{
		free(swap);
		return (1);
	}
	free(swap);
	return (0);
}

static int	clr_mem(char **memory, int mod, int bytes)
{
	if (mod == 1 && *memory && !ft_strlen(*memory))
	{
		free(*memory);
		*memory = NULL;
	}
	if (mod == 2)
	{
		if (bytes < 0)
		{
			free(*memory);
			return (1);
		}
	}
	if (mod == 3)
	{
		free(*memory);
		*memory = NULL;
		return (-1);
	}
	return (0);
}

static int	chk_buffer(char **line, char **buffer, char **sl_n)
{
	*sl_n = NULL;
	if (*buffer && ft_strlen(*buffer))
		if ((*sl_n = ft_strchr(*buffer, '\n')))
		{
			**sl_n = '\0';
			if (!(*line = ft_strdup(*buffer)))
				return (clr_mem(buffer, 3, 0));
			ft_strcpy(*buffer, ++(*sl_n));
		}
		else
		{
			if (!(*line = ft_strdup(*buffer)))
				return (clr_mem(buffer, 3, 0));
			(*buffer)[0] = '\0';
		}
	else
	{
		if (!(*line = ft_strdup("")))
			return (clr_mem(buffer, 3, 0));
	}
	clr_mem(buffer, 1, 0);
	return (0);
}

int			get_next_line(int fd, char **line)
{
	static char *buffer = NULL;
	char		temp[BUFFER_SIZE + 1];
	int			bytes_read;
	char		*sl_n;

	if (fd < 0 || line == NULL || BUFFER_SIZE <= 0)
		return (-1);
	if (chk_buffer(line, &buffer, &sl_n) < 0)
		return (-1);
	bytes_read = 1;
	while (!sl_n && (bytes_read = read(fd, temp, BUFFER_SIZE)))
	{
		if (clr_mem(line, 2, bytes_read))
			return (clr_mem(&buffer, 3, 0));
		temp[bytes_read] = '\0';
		if ((sl_n = ft_strchr(temp, '\n')))
		{
			*sl_n++ = '\0';
			if (clr_mem(&buffer, 3, 0) == -1 && !(buffer = ft_strdup(sl_n)))
				return (-1);
		}
		if (swap_mem(line, temp))
			return (clr_mem(&buffer, 3, 0));
	}
	return (buffer || bytes_read);
}
