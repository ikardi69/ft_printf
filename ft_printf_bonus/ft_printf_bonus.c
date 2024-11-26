/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 02:53:37 by mteffahi          #+#    #+#             */
/*   Updated: 2024/11/27 00:28:15 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"

static int	format_handler_bonus(va_list args, const char *s)
{
	int	precision;
	int size;

	size = 0;
	if (s == '.')
	{
		s++;
		precision = ft_atoi(s);
		size += ft_precision_handle_bonus(args, s, precision);
	}
		
}

int	ft_printf(const char *s, ...)
{
	int	i;
	int	size;
	va_list	args;
	// int track;

	va_start(args, s);
	i = 0;
	size = 0;
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			if (*s == '.')
				size += format_handler_bonus(args, s);
			// track = size;
			size += format_handler(args, s);
			// if (track < size)
				i++;
		}
		else
			size += ft_putchar(s++);
	}
	va_end(args);
	return (size);
}
