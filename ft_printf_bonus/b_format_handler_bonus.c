/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_format_handler_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 02:43:51 by mteffahi          #+#    #+#             */
/*   Updated: 2024/11/27 03:42:10 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"

static int	ft_dot(va_list args, const char *s)
{
	int precision;
	int	i;
	int tmp;
	int size;

	precision = ft_atoi(s);
	i = ft_skip(s);
	if (s[i] == 'd' || s[i] == 'i')
	{
		tmp = va_arg(args, int);
		size = 0;
		while (size < (precision - ft_nbr_size(tmp)) && ft_nbr_size(tmp) > precision)
			size += write(1, "0", 1);
		size += ft_putnbr(tmp);
	}
	else if (s[i] == 's')
		size += ft_putstr_precision(va_arg(args, char *), precision);
	return (size);
}

int	ft_bonus_format_handler(va_list args, const char *s)
{
	int size;

	size = 0;
	if (s[size] == '.')
	{
		s++;
		size += ft_dot(args, s);
	}
	return (size);
}
