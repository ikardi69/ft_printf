/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zero_paddding_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 04:48:57 by mteffahi          #+#    #+#             */
/*   Updated: 2024/11/28 05:21:39 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"

static int	ft_negative_zpadding(int tmp, int precision)
{
	int	size;

	size = 0;
	if (tmp < 0)
	{
		size += ft_putchar('-');
		while (size < (precision - ft_nbr_size(tmp)) && ft_nbr_size(tmp) < precision)
			size += write(1, "0", 1);
		size += ft_putnbr((tmp * -1));
	}
	else
	{
		while (size < (precision - ft_nbr_size(tmp)) && ft_nbr_size(tmp) < precision)
			size += write(1, "0", 1);
		size += ft_putnbr(tmp);
	}
	return (size);
}

int	ft_zero_padding(va_list args, const char *s)
{
	int	precision;
	int	i;
	int	size;

	precision = ft_atoi(s);
	i = ft_skip(s);
	size = 0;
	if (s[i] == 'd' || s[i] == 'i')
		size += ft_negative_zpadding(va_arg(args, int), precision);
	return (size);
}
