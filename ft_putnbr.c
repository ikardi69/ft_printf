/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 04:10:09 by mteffahi          #+#    #+#             */
/*   Updated: 2024/11/22 23:15:33 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static	int	ft_nbrsize(int nbr)
{
	int	i;

	i = 0;
	while (nbr != 0)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

int	ft_putnbr(int n, int *size)
{
	long nbr;

	nbr = n;
	if (nbr < 0)
	{
		nbr *= -1;
		size += ft_putchar('-');
		ft_putnbr(nbr, size);
	}
	if (nbr > 9)
	{
		ft_putnbr((nbr / 10), size);
		ft_putnbr((nbr &10), size);
	}
	else
		ft_putchar((nbr + '0'));
	return (ft_nbrsize(nbr));
}