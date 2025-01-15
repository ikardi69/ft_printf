/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util8_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:46:56 by mteffahi          #+#    #+#             */
/*   Updated: 2025/01/15 18:40:34 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_hex_upp_neg(unsigned int nbr, int precision)
{
	int	size;

	size = 0;
	size += ft_putnbr_hex_up(nbr);
    while (size < precision)
	{
        size += write(1, " ", 1);
	}
	return (size);
}

int	ft_putnbr_always_positive(long n)
{
	int		size;

	size = 0;
	if (n < 0)
		size += ft_putnbr_always_positive(n * -1);
	if (n > 9)
	{
		size += ft_putnbr_always_positive(n / 10);
		size += ft_putnbr_always_positive(n % 10);
	}
	else
		size += ft_putchar((n + '0'));
	return (size);
}

int ft_negative_zpadding_helper(int tmp)
{
    int     size;
    long    temp_l;

    size = 0;
	temp_l = (tmp * -1);
	size += (ft_putnbr_always_positive(temp_l * -1) + 1);
    return (size);
}

int	ft_hash_helper(unsigned int tmp)
{
	int	size;

	size = 0;
	if (tmp == 0)
		size += ft_putnbr_hex_low(tmp);
	else
		size += (ft_putstr("0X")
				+ ft_putnbr_hex_up(tmp));
	return (size);
}
