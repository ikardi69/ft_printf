/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util4_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 20:30:56 by mteffahi          #+#    #+#             */
/*   Updated: 2025/01/07 18:25:17 by mteffahi         ###   ########.fr       */
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
		size += ft_int_precision(args, flag, precision);
	else if (s[i] == 's')
		size += ft_putstr_precision(va_arg(args, char *), precision);
	else if (s[i] == 'u')
		size += ft_unsigned_precision(args, precision);
	else if (s[i] == 'x')
		size += ft_hex_low_dot(va_arg(args, unsigned int), precision);
	else if (s[i] == 'X')
		size += ft_hex_up_dot(va_arg(args, unsigned int), precision);
	else if (s[i] == 'z' && s[i + 1] == 'u')
	{
		i++;
		size += ft_size_t_precision(va_arg(args, size_t), precision);
	}
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

int	ft_nbr_unsigned_size(unsigned int nbr)
{
	int	i;

	i = 0;
	if (nbr == 0)
		return (1);
	while (nbr != 0)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}
