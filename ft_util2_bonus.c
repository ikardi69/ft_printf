/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util2_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 20:22:09 by mteffahi          #+#    #+#             */
/*   Updated: 2025/01/15 18:41:23 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hash(va_list args, const char *s)
{
	int				size;
	int				i;
	unsigned int	tmp;

	size = 0;
	i = 0;
	if (s[i] >= '0' && s[i] <= '9')
		size += ft_combination3(args, s);
	if (s[i] != 'x' && s[i] != 'X')
		size += format_handler(args, s[i]);
	if (s[i] == 'x')
	{
		tmp = va_arg(args, unsigned int);
		if (tmp == 0)
			size += ft_putnbr_hex_low(tmp);
		else
			size += (ft_putstr("0x")
					+ ft_putnbr_hex_low(tmp));
	}
	else if (s[i] == 'X')
		size += ft_hash_helper(va_arg(args, unsigned int));
	return (size);
}

int	format_handler(va_list args, const char s)
{
	int	size;

	size = 0;
	if (s == 'c')
		size += ft_putchar(va_arg(args, int));
	else if (s == 's')
		size += ft_putstr(va_arg(args, char *));
	else if (s == 'p')
		size += ft_printf_ptr_adress(va_arg(args, void *));
	else if (s == 'd' || s == 'i')
		size += ft_putnbr(va_arg(args, int));
	else if (s == 'u')
		size += ft_put_unsigned(va_arg(args, unsigned int));
	else if (s == 'x')
		size += ft_putnbr_hex_low(va_arg(args, unsigned int));
	else if (s == 'X')
		size += ft_putnbr_hex_up(va_arg(args, unsigned int));
	else if (s == '%')
		size += write(1, "%", 1);
	return (size);
}

int	ft_hexa_size(unsigned int value)
{
	int	size;

	size = 0;
	if (value == 0)
		return (1);
	while (value != 0)
	{
		value /= 16;
		size ++;
	}
	return (size);
}

int	ft_nbr_size(int nbr)
{
	int	i;

	i = 0;
	if (nbr == 0)
		return (1);
	else if (nbr < 0)
		i += 1;
	while (nbr != 0)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

int	ft_positive_sign(int nbr)
{
	int	size;

	size = 0;
	if (nbr < 0)
		size += ft_putnbr(nbr);
	else
		size += (ft_putchar('+') + ft_putnbr(nbr));
	return (size);
}
