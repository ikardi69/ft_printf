/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 14:12:34 by mteffahi          #+#    #+#             */
/*   Updated: 2025/01/07 17:32:50 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"

static int	padding(int w, int m)
{
	int	i;

	i = 0;
	while (i < (w - m))
		i += write(1, " ", 1);
	return (i);
}

static int	ft_int_handler(int nbr, int width)
{
	int	size;

	size = 0;
	if (nbr < 0)
		size += (padding(width, ft_nbr_size(nbr)) + ft_putnbr(nbr));
	else
		size += (padding(width, (ft_nbr_size(nbr) + 1))
				+ ft_putchar('+') + ft_putnbr(nbr));
	return (size);
}

int	ft_combination1(va_list args, const char *s)
{
	int	width;
	int	size;
	int	i;
	int	tmp;

	width = ft_atoi(s);
	i = ft_skip(s);
	size = 0;
	if (s[i] == 'd' || s[i] == 'i')
	{
		tmp = va_arg(args, int);
		size += ft_int_handler(tmp, width);
	}
	return (size);
}

int	ft_combination3(va_list args, const char *s)
{
	int				width;
	int				size;
	unsigned int	tmp;

	size = 0;
	width = (ft_atoi(s) - 2);
	tmp = va_arg(args, unsigned int);
	size = ft_skip(s);
	if (s[size] == 'x')
		size = padding(width, ft_hexa_size(tmp))
			+ ft_putstr("0x") + ft_putnbr_hex_low(tmp);
	else if (s[size] == 'X')
		size = padding(width, ft_hexa_size(tmp))
			+ ft_putstr("0X") + ft_putnbr_hex_up(tmp);
	return (size);
}
int	ft_nbr_size_t(size_t nbr)
{
	int	i;

	i = 0;
	if (nbr == 0)
		return (1);
	while (nbr != 0)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}
