/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 10:59:49 by mteffahi          #+#    #+#             */
/*   Updated: 2024/12/07 17:21:19 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"

int	ft_hash(va_list args, const char *s)
{
	int	size;
	int	i;

	size = 0;
	i = 0;
	// if (s[i] >= '0' && s[i] <= '9')
	if (s[i] != 'x' && s[i] != 'X')
		size += format_handler(args, s[i]);
	if (s[i] == 'x')
		size += (ft_putstr("0x") + ft_putnbr_hex_low(va_arg(args, unsigned int)));
	else if (s[i] == 'X')
		size += (ft_putstr("0X") + ft_putnbr_hex_up(va_arg(args, unsigned int)));
	return (size);
}
