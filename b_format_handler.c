/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_format_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 02:43:51 by mteffahi          #+#    #+#             */
/*   Updated: 2025/01/15 18:49:03 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_check_flag(int *size, const char *s, va_list args)
{
	if (s[*size] == '.')
		*size += ft_dot(args, s + 1);
	else if (s[*size] == '-' && s[*size + 1] == '+')
		*size += ft_negative_handle(args, s + 1);
	else if (s[*size] == '-' && s[*size + 1] != '+')
		*size += ft_negative_handle(args, s + 1);
	else if (s[*size] == '0')
		*size += ft_zero_padding(args, s + 1);
	else if (s[*size] == ' ' && s[*size + 1] >= '0' && s[*size + 1] <= '9')
		*size += ft_field_minimum_width(args, s + 1);
	else if (s[*size] >= '0' && s[*size] <= '9')
		*size += ft_field_minimum_width(args, s);
	else if (s[*size] == '#')
		*size += ft_hash(args, s + 1);
}

int	ft_bonus_format_handler(va_list args, const char *s)
{
	int	size;

	size = 0;
	ft_check_flag(&size, s, args);
	if (s[size] == ' ' && (s[size + 1] == 'd' || s[size + 1] == 'i'))
		size += ft_space_handler(va_arg(args, int));
	else if (s[size] == '+' && (s[size + 1] == 'd' || s[size + 1] == 'i'))
		size += ft_positive_sign(va_arg(args, int));
	else if (s[size] == ' ' && s[size + 1] == '+')
		size += ft_positive_sign(va_arg(args, int));
	else if (s[size] == '+' && ((s[size + 1] >= '0' && s[size + 1] <= '9')
			|| s[size + 1] == ' '))
		size += ft_combination1(args, s + 1);
	else if (s[size] == ' ' && s[size + 1] == 's')
		size += ft_putstr(va_arg(args, char *));
	return (size);
}

int	ft_int_precision(va_list args, int flag, int precision)
{
	int		size;
	long	tmp;

	size = 0;
	tmp = va_arg(args, int);
	flag = ft_check_tmp_int(&tmp);
	while (size < (precision - ft_nbr_size(tmp))
		&& ft_nbr_size(tmp) < precision)
		size += write(1, "0", 1);
	size += ft_putnbr_always_positive(tmp);
	if (flag == 1)
		size++;
	return (size);
}

int	ft_check_tmp_int(long *tmp)
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

int	ft_put_unsigned_nbr(unsigned int n)
{
	int		size;

	size = 0;
	if (n > 9)
	{
		size += ft_put_unsigned_nbr(n / 10);
		size += ft_put_unsigned_nbr(n % 10);
	}
	else
		size += ft_putchar((n + '0'));
	return (size);
}
