/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_negative_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 00:20:32 by mteffahi          #+#    #+#             */
/*   Updated: 2024/12/07 17:00:31 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"

static int	ft_put(int tmp, int precision)
{
	int	i;

	i = 0;
	while (i < (precision - ft_nbr_size(tmp)) && ft_nbr_size(tmp) < precision)
		i += write(1, " ", 1);
	return (i);
}

static int	ft_put_char_precision(va_list args, int precision)
{
	int	size;

	size = 0;
	size += ft_putchar(va_arg(args, int));
	while (size < precision)
		size += write(1, " ", 1);
	return (size);
}

static int	ft_putstr_negative(va_list args, int precision)
{
	int	size;

	size = 0;
	size += ft_putstr(va_arg(args, char *));
	while (size < precision)
		size += write(1, " ", 1);
	return (size);
}

int	 ft_negative_handle(va_list args, const char *s)
{
	int					precision;
	int					i;
	int					size;
	unsigned long long	tmp;

	precision = ft_atoi(s);
	i = ft_skip(s);
	size = 0;
	if (s[size] == ' ')
		ft_putchar(' ');
	if (s[i] == 'd' || s[i] == 'i')
	{
		tmp = va_arg(args, int);
		if (s[size] == '+' && tmp > 0)
		{
			size++;
			precision -= ft_putchar('+');
		}
		size += (ft_putnbr(tmp) + ft_put(tmp, precision));
	}
	else if (s[i] == 'c')
		size += ft_put_char_precision(args, precision);
	else if (s[i] == 's')
		size += ft_putstr_negative(args, precision);
	else if (s[i] == 'p')
	{
		tmp = (unsigned long long)va_arg(args , void *);
		size += (ft_printf_ptr_adress((void *)tmp) + ft_put(tmp, (precision - 2)));
	}
	else if (s[i] == 'u')
	{
		tmp = va_arg(args, unsigned int);
		size += ft_put_unsigned(tmp) + ft_put(tmp, precision);
	}
	else if (s[i] == '#')
		size += ft_combination2(args, s+1);
	return (size);
}
