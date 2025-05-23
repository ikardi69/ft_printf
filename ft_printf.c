/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 02:53:37 by mteffahi          #+#    #+#             */
/*   Updated: 2025/01/14 18:07:48 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_is_bonus_flag(char c)
{
	if (c == '+' || c == ' ' || c == '#' || c == '.' || c == '-'
		|| c == '0' || (c >= '0' && c <= '9'))
		return (1);
	else
		return (0);
}

static int	ft_is_mandatory_flag(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'
		|| c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	else
		return (0);
}

static int	ft_get_size(const char *s, va_list args)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '%' && s[i + 1] != '\0')
		{
			i++;
			if (ft_is_bonus_flag(s[i]))
			{
				size += ft_bonus_format_handler(args, (s + i));
				i += ft_skip_pf(s + (i + 1)) + 1;
			}
			else if (ft_is_mandatory_flag(s[i]))
				size += format_handler(args, s[i]);
			i++;
		}
		else
			size += ft_putchar(s[i++]);
	}
	return (size);
}

int	ft_printf(const char *s, ...)
{
	int		size;
	va_list	args;

	if (write(1, 0, 0) == -1)
		return (-1);
	va_start(args, s);
	size = ft_get_size(s, args);
	va_end(args);
	return (size);
}
