/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_negative_utils_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 19:21:24 by mteffahi          #+#    #+#             */
/*   Updated: 2025/01/05 21:23:44 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"

int	ft_put(int tmp, int precision)
{
	int	i;

	i = 0;
	while (i < (precision - ft_nbr_size(tmp)) && ft_nbr_size(tmp) < precision)
		i += write(1, " ", 1);
	return (i);
}

void	ft_handle_integer(const char *s, va_list args, int *size,
		unsigned long long *tmp)
{
	int	precision;
	int	i;

	precision = ft_atoi(s);
	i = ft_skip(s);
	if (s[i] == 'd' || s[i] == 'i')
	{
		*tmp = va_arg(args, int);
		if (s[*size] == '+' && *tmp > 0)
		{
			*size += 1;
			precision -= ft_putchar('+');
		}
		*size += (ft_putnbr(*tmp) + ft_put(*tmp, precision));
	}
}

void	ft_handle_str(const char *s, va_list args, int *size)
{
	int	precision;
	int	i;

	precision = ft_atoi(s);
	i = ft_skip(s);
	if (s[i] == 'c')
		*size += ft_put_char_precision(args, precision);
	else if (s[i] == 's')
		*size += ft_putstr_negative(args, precision);
}

void	ft_handle_ptr(const char *s, va_list args, int *size,
		unsigned long long *tmp)
{
	int	precision;
	int	i;

	precision = ft_atoi(s);
	i = ft_skip(s);
	if (s[i] == 'p')
	{
		*tmp = (unsigned long long)va_arg(args, void *);
		*size += (ft_printf_ptr_adress((void *)*tmp)
				+ ft_put(*tmp, (precision - 2)));
	}
	else if (s[i] == 'u')
	{
		*tmp = va_arg(args, unsigned int);
		*size += ft_put_unsigned(*tmp) + ft_put(*tmp, precision);
	}
}

int	ft_size_t_size(size_t nbr)
{
	int	size;

	size = 0;
	if (nbr == 0)
		return (1);
	while (nbr != 0)
	{
		nbr /= 10;
		size++;
	}
	return (size);
}
