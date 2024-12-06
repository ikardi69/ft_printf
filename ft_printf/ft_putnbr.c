/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 04:10:09 by mteffahi          #+#    #+#             */
/*   Updated: 2024/12/04 10:11:43 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putnbr(int n)
{
	long nbr;
	int	size;

	size = 0;
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	nbr = n;
	if (nbr < 0)
	{
		nbr *= -1;
		size += ft_putchar('-');
		size += ft_putnbr(nbr);
	}
	else if (nbr > 9)
	{
		size += ft_putnbr(nbr / 10);
		size += ft_putnbr(nbr % 10);
	}
	else
		size += ft_putchar((nbr + '0'));
	return (size);
}
