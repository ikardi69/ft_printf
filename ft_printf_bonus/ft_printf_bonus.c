/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 02:53:37 by mteffahi          #+#    #+#             */
/*   Updated: 2024/11/26 22:30:19 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"

static int	format_handler_bonus(va_list args, const char *s, int *i)
{
	int	x;
	int	precision;
	
	x = &i;
	if (s[x] == '.')
	{
		precision = ft_atoi(s+x);
		
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
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			i++;
			if (s[i] == '.')
				size += format_handler_bonus(args, s, &i);
			// track = size;
			size += format_handler(args, s[i]);
			// if (track < size)
				i++;
		}
		else
			size += ft_putchar(s[i++]);
	}
	va_end(args);
	return (size);
}
