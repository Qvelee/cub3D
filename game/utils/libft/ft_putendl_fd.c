/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 23:31:32 by nelisabe          #+#    #+#             */
/*   Updated: 2020/05/22 20:00:43 by nelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *str, int discriptor)
{
	if (!(str))
		return ;
	ft_putstr_fd(str, discriptor);
	ft_putchar_fd('\n', discriptor);
}
