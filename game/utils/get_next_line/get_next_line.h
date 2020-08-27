/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 13:39:21 by nelisabe          #+#    #+#             */
/*   Updated: 2020/08/26 16:46:32 by nelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

# include <unistd.h>
# include <stdlib.h>

int		get_next_line(int fd, char **line);
char	*ft_strjoin_m(char *str1, char *str2);
char	*ft_strchr_m(const char *str_in, int symbol);
size_t	ft_strcpy_m(char *dst, const char *src);
char	*ft_strdup_m(const char *str);
size_t	ft_strlen_m(const char *str);

#endif
