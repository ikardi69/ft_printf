/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_format_handler_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 02:43:51 by mteffahi          #+#    #+#             */
/*   Updated: 2024/12/15 20:47:22 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"

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
	return (size);
}

int	ft_int_precision(va_list args, int flag, int precision)
{
	int	size;
	int	tmp;

	size = 0;
	tmp = va_arg(args, int);
	flag = ft_check_tmp(&tmp);
	while (size < (precision - ft_nbr_size(tmp))
		&& ft_nbr_size(tmp) < precision)
		size += write(1, "0", 1);
	size += ft_putnbr(tmp);
	if (flag == 1)
		size++;
	return (size);
}
