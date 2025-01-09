/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util1_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 16:49:54 by mteffahi          #+#    #+#             */
/*   Updated: 2025/01/07 18:26:20 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"

static int	ft_put_comb(unsigned int tmp, int precision)
{
	int	i;

	i = 0;
	while (i < (precision - ft_nbr_size(tmp)) && ft_nbr_size(tmp) < precision)
		i += write(1, " ", 1);
	return (i);
}

static int	ft_hash_comb(unsigned int tmp, const char *s)
{
	int	size;

	size = 0;
	if (s[size] == 'x')
		size += (ft_putstr("0x") + ft_putnbr_hex_low(tmp));
	else if (s[size] == 'X')
		size += (ft_putstr("0X") + ft_putnbr_hex_up(tmp));
	return (size);
}

int	ft_combination2(va_list args, const char*s)
{
	int				precision;
	int				size;
	unsigned int	tmp;
	int				i;

	precision = ft_atoi(s);
	size = 0;
	i = ft_skip(s);
	tmp = va_arg(args, unsigned int);
	size += (ft_hash_comb(tmp, s + i) + ft_put_comb(tmp, precision - 2));
	return (size);
}

int	ft_skip_pf(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && ((s[i] >= '0' && s[i] <= '9')
			|| s[i] == '+' || s[i] == ' ' || s[i] == '#'))
		i++;
	return (i);
}

int	ft_hex_up_dot(unsigned int nbr, int precision)
{
	int	size;
	int	len;

	len = ft_hexa_size(nbr);
	size = 0;
	while (size < (precision - len))
	{
		size += write(1, "0", 1);
	}
	size += ft_putnbr_hex_up(nbr);
	return (size);
}
