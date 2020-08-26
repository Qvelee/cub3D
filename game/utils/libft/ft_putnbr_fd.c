/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 23:50:17 by nelisabe          #+#    #+#             */
/*   Updated: 2020/05/19 22:46:25 by nelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int num, int discriptor)
{
	long number;

	number = (long)num;
	if (number < 0)
	{
		ft_putchar_fd('-', discriptor);
		number *= -1;
	}
	if (number >= 10)
		ft_putnbr_fd(number / 10, discriptor);
	ft_putchar_fd(number % 10 + '0', discriptor);
}
