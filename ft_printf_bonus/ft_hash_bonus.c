/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 10:59:49 by mteffahi          #+#    #+#             */
/*   Updated: 2024/12/03 11:08:53 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"

int	ft_hash(va_list args, const char *s)
{
	int	size;

	size = 0;
	if (s[size] == 'x')
		size += (ft_putstr("0x") + ft_putnbr_hex_low(va_arg(args, unsigned int)));
	else if (s[size] == 'X')
		size += (ft_putstr("0X") + ft_putnbr_hex_up(va_arg(args, unsigned int)));
	return (size);
}