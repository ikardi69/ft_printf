/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util4_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 20:30:56 by mteffahi          #+#    #+#             */
/*   Updated: 2024/12/15 21:28:26 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"

int	ft_putnbr_hex_low(unsigned int nbr)
{
	char	*hex;
	int		size;

	hex = "0123456789abcdef";
	size = 0;
	if (nbr == 0)
		return (write(1, "0", 1));
	if (nbr / 16 != 0)
		size = ft_putnbr_hex_low(nbr / 16);
	else
		size = 0;
	size += write(1, &hex[nbr % 16], 1);
	return (size);
}

int	ft_putnbr_hex_up(unsigned int nbr)
{
	char	*hex;
	int		size;

	hex = "0123456789ABCDEF";
	size = 0;
	if (nbr == 0)
		return (write(1, "0", 1));
	if (nbr / 16 != 0)
		size = ft_putnbr_hex_up(nbr / 16);
	else
		size = 0;
	size += write(1, &hex[nbr % 16], 1);
	return (size);
}

static int	ft_check_tmp(int *tmp)
{
	int	flag;

	flag = 0;
	if (*tmp < 0)
	{
		write(1, "-", 1);
		*tmp *= -1;
		flag = 1;
	}
	return (flag);
}

int	ft_dot(va_list args, const char *s)
{
	int	precision;
	int	i;
	int	tmp;
	int	size;
	int	flag;

	precision = ft_atoi(s);
	i = ft_skip(s);
	size = 0;
	if (s[i] == 'd' || s[i] == 'i')
	{
		tmp = va_arg(args, int);
		flag = ft_check_tmp(&tmp);
		while (size < (precision - ft_nbr_size(tmp))
			&& ft_nbr_size(tmp) < precision)
			size += write(1, "0", 1);
		size += ft_putnbr(tmp);
		if (flag == 1)
			size++;
	}
	else if (s[i] == 's')
		size += ft_putstr_precision(va_arg(args, char *), precision);
	return (size);
}

int	ft_putstr(char *s)
{
	int	i;

	if (!s)
		s = "(null)";
	i = 0;
	while (s[i])
		i++;
	return (write(1, s, i));
}
