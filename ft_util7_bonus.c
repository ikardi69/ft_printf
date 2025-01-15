/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util7_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:46:50 by mteffahi          #+#    #+#             */
/*   Updated: 2025/01/15 15:32:33 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_space_p(unsigned int nbr, int width)
{
	int	size;

	size = 0;
	while (size < (width - ft_hexa_size(nbr)))
		size += write(1, " ", 1);
	size += (ft_putstr("0x") + ft_putnbr_hex_low(nbr));
	return (size);
}
int	ft_put_llu(unsigned long long tmp, int precision)
{
	int	size;

	size = 0;
	size += ft_printf_ptr_adress((void *)tmp);
    while (size < precision)
	{
        size += write(1, " ", 1);
	}
	return (size);
}

int	ft_hexa_ptr_size(unsigned long long value)
{
	int	size;

	size = 0;
	if (value == 0)
		return (1);
	while (value != 0)
	{
		value /= 16;
		size++;
	}
	return (size);
}

int	ft_unsigned_negative(unsigned int nbr, int precision)
{
	int	size;

	size = 0;
	size += ft_put_unsigned_nbr(nbr);
    while (size < precision)
	{
        size += write(1, " ", 1);
	}
	return (size);
}

int	ft_hex_low_neg(unsigned int nbr, int precision)
{
	int	size;

	size = 0;
	size += ft_putnbr_hex_low(nbr);
    while (size < precision)
	{
        size += write(1, " ", 1);
	}
	return (size);
}
