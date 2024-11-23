/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 04:10:09 by mteffahi          #+#    #+#             */
/*   Updated: 2024/11/23 20:12:56 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putnbr(int n)
{
	long nbr;
	int	size;

	nbr = n;
	size = 0;
	if (nbr < 0)
	{
		nbr *= -1;
		size += ft_putchar('-');
		ft_putnbr(nbr);
	}
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
	else
		size += ft_putchar((nbr + '0'));
	return (size);
}