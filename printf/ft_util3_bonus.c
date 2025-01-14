/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util3_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 20:27:17 by mteffahi          #+#    #+#             */
/*   Updated: 2025/01/14 17:14:15 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_hex(unsigned long long num, char *hexa)
{
	int	len;

	if (num == 0)
		return (0);
	len = print_hex(num / 16, hexa);
	return (len + write(1, &hexa[num % 16], 1));
}

int	ft_printf_ptr_adress(void	*ptr)
{
	unsigned long long	value;
	char				*hexa;
	int					counter;

	if (!ptr)
		return (write (1, "0x0", 3));
	value = (unsigned long long)ptr;
	hexa = "0123456789abcdef";
	counter = write(1, "0x", 2);
	if (value == 0)
		counter += write(1, "0", 1);
	else
		counter += print_hex(value, hexa);
	return (counter);
}

int	ft_put_unsigned(unsigned int n)
{
	int	size;

	size = 0;
	if (n > 9)
	{
		size += ft_putnbr(n / 10);
		size += ft_putnbr(n % 10);
	}
	else
		size += ft_putchar((n + '0'));
	return (size);
}

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putnbr(int n)
{
	int		size;

	size = 0;
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	if (n < 0)
	{
		n *= -1;
		size += ft_putchar('-');
		size += ft_putnbr(n);
	}
	else if (n > 9)
	{
		size += ft_putnbr(n / 10);
		size += ft_putnbr(n % 10);
	}
	else
		size += ft_putchar((n + '0'));
	return (size);
}
