/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_space_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 12:49:42 by mteffahi          #+#    #+#             */
/*   Updated: 2024/12/03 14:56:59 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"

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
