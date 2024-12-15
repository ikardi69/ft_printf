/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 02:53:37 by mteffahi          #+#    #+#             */
/*   Updated: 2024/12/15 21:09:35 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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
	int		i;
	int		size;
	va_list	args;
	int		track;

	if ((write(0, 0, 0)) < 0 || (write(1, 0, 0)) < 0 || (write(2, 0, 0)) < 0)
		return (-1);
	va_start(args, s);
	i = 0;
	size = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '%' && s[i + 1] != '\0')
		{
			i++;
			track = size;
			size += format_handler(args, s[i]);
			if (track < size)
				i++;
		}
		else
			size += ft_putchar(s[i++]);
	}
	va_end(args);
	return (size);
}
