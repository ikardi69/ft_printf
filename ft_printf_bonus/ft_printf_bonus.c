/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 02:53:37 by mteffahi          #+#    #+#             */
/*   Updated: 2024/11/28 00:18:34 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"

static int	format_handler(va_list args, const char s)
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

int	ft_printf(const char *s, ...)
{
	int	i;
	int	size;
	va_list	args;

	va_start(args, s);
	i = 0;
	size = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			i++;
			if (s[i] == '.' || s[i] == '-')
			{
				size += ft_bonus_format_handler(args, s+i);
				i += ft_skip(s + (i + 1)) + 1;
			}
			else
				size += format_handler(args, s[i]);
			i++;
		}
		else
			size += ft_putchar(s[i++]);
	}
	va_end(args);
	return (size);
}
