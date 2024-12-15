/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util5_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 20:33:57 by mteffahi          #+#    #+#             */
/*   Updated: 2024/12/15 20:53:44 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"

static int	padding(int w, int m)
{
	int	i;

	i = 0;
	while (i < (w - m))
		i += write(1, " ", 1);
	return (i);
}

int	ft_field_minimum_width(va_list args, const char *s)
{
	int		width;
	int		size;
	int		i;
	char	*ptr;

	width = ft_atoi(s);
	i = ft_skip(s);
	size = 0;
	if (s[i] == 'c')
		size += (padding(width, 1) + ft_putchar(va_arg(args, int)));
	else if (s[i] == 's')
	{
		ptr = va_arg(args, char *);
		size += (padding(width, ft_strlen(ptr)) + ft_putstr(ptr));
	}
	else if (s[i] == 'd' || s[i] == 'i')
	{
		i = va_arg(args, int);
		size += (padding(width, ft_nbr_size(i)) + ft_putnbr(i));
	}
	return (size);
}

int	ft_putstr_precision(const char *s, int precision)
{
	int		i;
	char	*n;

	i = 0;
	if (!s)
	{
		n = "(null)";
		while (n[i] != '\0' && i < precision)
		{
			write(1, &n[i], 1);
			i++;
		}
		return (i);
	}
	while (s[i] != '\0' && i < precision)
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_skip(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && ((s[i] >= '0' && s[i] <= '9')
			|| s[i] == '+' || s[i] == ' '))
		i++;
	return (i);
}

int	ft_space_handler(int nbr)
{
	int	size;

	size = 0;
	if (nbr < 0)
		size += ft_putnbr(nbr);
	else
		size += (ft_putchar(' ') + ft_putnbr(nbr));
	return (size);
}
