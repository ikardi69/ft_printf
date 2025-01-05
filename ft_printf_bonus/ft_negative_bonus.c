/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_negative_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 00:20:32 by mteffahi          #+#    #+#             */
/*   Updated: 2024/12/15 19:29:15 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"

int	ft_put_char_precision(va_list args, int precision)
{
	int	size;

	size = 0;
	size += ft_putchar(va_arg(args, int));
	while (size < precision)
		size += write(1, " ", 1);
	return (size);
}

int	ft_putstr_negative(va_list args, int precision)
{
	int	size;

	size = 0;
	size += ft_putstr(va_arg(args, char *));
	while (size < precision)
		size += write(1, " ", 1);
	return (size);
}

int	ft_negative_handle(va_list args, const char *s)
{
	int					i;
	int					size;
	unsigned long long	tmp;

	i = ft_skip(s);
	size = 0;
	if (s[size] == ' ')
		ft_putchar(' ');
	ft_handle_integer(s, args, &size, &tmp);
	ft_handle_str(s, args, &size);
	ft_handle_ptr(s, args, &size, &tmp);
	if (s[i] == '#')
		size += ft_combination2(args, s + 1);
	return (size);
}

int	ft_unsigned_precision(va_list args, int flag, int precision)
{
	int				size;
	unsigned int	tmp;

	size = 0;
	tmp = va_arg(args, unsigned int);
	flag = ft_check_tmp(&tmp);
	while (size < (precision - ft_nbr_size(tmp))
		&& ft_nbr_size(tmp) < precision)
		size += write(1, "0", 1);
	size += ft_putnbr(tmp);
	if (flag == 1)
		size++;
	return (size);
}
