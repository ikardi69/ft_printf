/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_adress_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 20:38:18 by mteffahi          #+#    #+#             */
/*   Updated: 2024/11/27 02:39:57 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"

static int	print_hex(unsigned long long num, char *hexa)
{
	int len;
        
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
		return (write (1, "0", 1));
	value = (unsigned long long)ptr;
	hexa = "0123456789abcdef";
    counter = write(1, "0x", 2);
	if (value == 0)
		counter += write(1, "0", 1);
	else
		counter += print_hex(value, hexa);
	return (counter);
}
