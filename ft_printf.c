/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 02:53:37 by mteffahi          #+#    #+#             */
/*   Updated: 2024/11/22 23:39:35 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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
		if (s[i] == '%' && i++)
		{
			if (s[i] == 'c')
				size += ft_putchar(va_arg(args, int));
			else if (s[i] == 's')
				size += ft_putstr(va_arg(args, char *));
			else if (s[i] == 'p')
				size += ft_printf_adress(va_arg(args, void *));
			else if (s[i] == 'd')
				size += ft_putnbr(va_arg(args, int), &size);
		}
		else
			size += ft_putchar(s[i++]);
	}
	va_end(args);
	return (size + i);
}
