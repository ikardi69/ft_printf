/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_adress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 20:38:18 by mteffahi          #+#    #+#             */
/*   Updated: 2024/11/23 03:32:02 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf_ptr_adress(void	*ptr)
{
	unsigned long long	value;
	char				*hexa;
	char				*result;
	int					i;

	value = (unsigned long long)ptr;
	result = (char *)malloc(20);
	if (!result)
		return (0);
	hexa = "0123456789abcdef";
	i = 0;
	while (value > 0)
	{
		result[i] = hexa[value % 16];
		value /= 16;
		i++;
	}
	result[i] = '\0';
	write(1, "0x", 2);
	while (--i >= 0)
	{
		write(1, &result[i], 1);
		i--;
	}
	free(result);
	return ((ft_strlen(result)+2));
}
