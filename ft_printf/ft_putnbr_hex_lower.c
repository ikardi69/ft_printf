/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex_lower.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 01:14:44 by mteffahi          #+#    #+#             */
/*   Updated: 2024/11/26 04:58:54 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putnbr_hex_low(unsigned int nbr)
{
	char 	*hex;
	int		size;
	
	hex = "0123456789abcdef";
	size = 0;
	if (nbr == 0)
		return (write(1, "0", 1));
    if (nbr / 16 != 0)
        size = ft_putnbr_hex_low(nbr / 16);
    else
        size = 0;
    size += write(1, &hex[nbr % 16], 1);
	return (size);
}