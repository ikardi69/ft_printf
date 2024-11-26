/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex_upper_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 22:00:01 by mteffahi          #+#    #+#             */
/*   Updated: 2024/11/26 19:35:40 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"

int	ft_putnbr_hex_up(unsigned int nbr)
{
	char 	*hex;
	int		size;
	
	hex = "0123456789ABCDEF";
	size = 0;
	if (nbr == 0)
		return (write(1, "0", 1));
    if (nbr / 16 != 0)
        size = ft_putnbr_hex_up(nbr / 16);
    else
        size = 0;
    size += write(1, &hex[nbr % 16], 1);
	return (size);
}