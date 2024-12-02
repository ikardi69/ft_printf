/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dot_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 17:53:44 by mteffahi          #+#    #+#             */
/*   Updated: 2024/12/02 13:26:32 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"

int	ft_dot(va_list args, const char *s)
{
	int precision;
	int	i;
	int tmp;
	int size;

	precision = ft_atoi(s);
	i = ft_skip(s);
	if (s[i] == 'd' || s[i] == 'i')
	{
		size = 0;
		tmp = va_arg(args, int);
		if (tmp < 0)
		{
			write(1, "-", 1);
			tmp *= -1;
		}
		while (size < (precision - ft_nbr_size(tmp)) && ft_nbr_size(tmp) < precision)
			size += write(1, "0", 1);
		size += ft_putnbr(tmp);
	}
	else if (s[i] == 's')
		size += ft_putstr_precision(va_arg(args, char *), precision);
	return (size);
}
