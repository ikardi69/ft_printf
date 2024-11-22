/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_adress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 20:38:18 by mteffahi          #+#    #+#             */
/*   Updated: 2024/11/22 23:41:16 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static	void	ft_rev(char *result, size_t	end)
{
	size_t	i;
	size_t	size;
	char	tmp;

	i = 0;
	size = end - 1;
	while (i < size)
	{
		tmp = result[i];
		result[i] = result[size];
		result[size] = tmp;
		i++;
		size--;
	}
}

int	ft_printf_adress(void	*ptr)
{
	unsigned int	value;
	char		*hexa;
	char		result[17];
	int			i;

	value = (unsigned int)ptr;
	hexa = "0123456789abcdef";
	i = 0;
	while (value != 0)
	{
		result[i] = hexa[value % 16];
		value /= 16;
		i++;
	}
	result[i] = '\0';
	ft_rev(result, i);
	ft_putstr("0x");
	return ((ft_putstr(result) + 2));
}