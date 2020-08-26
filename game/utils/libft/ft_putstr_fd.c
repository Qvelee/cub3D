/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 23:21:30 by nelisabe          #+#    #+#             */
/*   Updated: 2020/05/22 18:04:27 by nelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *str, int discriptor)
{
	long index;

	index = -1;
	if (!(str))
		return ;
	while (str[++index] != '\0')
		ft_putchar_fd(str[index], discriptor);
}
