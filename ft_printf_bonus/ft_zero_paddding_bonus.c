/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zero_paddding_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 04:48:57 by mteffahi          #+#    #+#             */
/*   Updated: 2025/01/05 18:12:54 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"

static int	ft_hexa_zpadding(unsigned int tmp, int precision, const char s)
{
	int	size;

	size = 0;
	if (s == 'x')
	{
		while (size < (precision - ft_hexa_size(tmp)))
			size += write(1, "0", 1);
		size += ft_putnbr_hex_low(tmp);
	}
	else if (s == 'X')
	{
		while (size < (precision - ft_hexa_size(tmp)))
			size += write(1, "0", 1);
		size += ft_putnbr_hex_up(tmp);
	}
	return (size);
}

static int	ft_negative_zpadding(int tmp, int precision)
{
	int	size;

	size = 0;
	if (tmp < 0)
	{
		size += ft_putchar('-');
		while (size < (precision - ft_nbr_size(tmp))
			&& ft_nbr_size(tmp) < precision)
			size += write(1, "0", 1);
		size += ft_putnbr((tmp * -1));
	}
	else
	{
		while (size < (precision - ft_nbr_size(tmp))
			&& ft_nbr_size(tmp) < precision)
			size += write(1, "0", 1);
		size += ft_putnbr(tmp);
	}
	return (size);
}

static int	ft_negative_zpadding_u(unsigned int tmp, int precision)
{
	int	size;

	size = 0;
	while (size < (precision - ft_nbr_size(tmp))
		&& ft_nbr_size(tmp) < precision)
		size += write(1, "0", 1);
	size += ft_put_unsigned(tmp);
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
	else if (s[i] == 'x' || s[i] == 'X')
		size += ft_hexa_zpadding(va_arg(args, unsigned int), precision, s[i]);
	else if (s[i] == 'u')
		size += ft_negative_zpadding_u(va_arg(args, unsigned int), precision);
	return (size);
}

int	ft_hex_low_dot(unsigned int nbr, int precision)
{
	int	size;
	int	len;

	len = ft_hexa_size(nbr);
	size = 0;
	while (size < (precision - len))
	{
		size += write(1, "0", 1);
	}
	size += ft_putnbr_hex_low(nbr);
	return (size);
}
