/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_handler_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 22:19:42 by mteffahi          #+#    #+#             */
/*   Updated: 2024/11/26 22:20:12 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"

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
	else if (s == '-')
	return (size);
}