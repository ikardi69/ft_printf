/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision_handle_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 21:45:48 by mteffahi          #+#    #+#             */
/*   Updated: 2024/11/27 00:48:07 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"

static int	ft_putnbrsize(int nbr)
{
	int i;

	i = 0;
	while (nbr != 0)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

int	ft_precision_handle(va_list args, const char *s, int precision)
{
	size_t	i;
	int tmp;

	i = 0;
	while (s[i] >= '0' && s[i] <= '9')
		s++;
	if (*s == 'd' || *s == 'i')
	{
		tmp = va_arg(args, int);
		if (ft_putnbrsize(tmp) > precision)
			return (ft_putnbr(tmp));
		precision = precision - ft_putnbrsize(tmp);
		while ()
		{
			/* code */
		}
		
	}
		
}
