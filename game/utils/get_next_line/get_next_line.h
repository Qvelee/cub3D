/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 13:39:21 by nelisabe          #+#    #+#             */
/*   Updated: 2020/07/06 20:30:18 by nelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

int		get_next_line(int fd, char **line);
char	*ft_strjoin(char *str1, char *str2);
char	*ft_strchr(const char *str_in, int symbol);
size_t	ft_strcpy(char *dst, const char *src);
char	*ft_strdup(const char *str);
size_t	ft_strlen(const char *str);

#endif
