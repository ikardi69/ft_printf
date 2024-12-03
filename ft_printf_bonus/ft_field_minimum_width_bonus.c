/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_field_minimum_width_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:29:45 by mteffahi          #+#    #+#             */
/*   Updated: 2024/12/03 10:52:11 by mteffahi         ###   ########.fr       */
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
// type problem for padding
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
