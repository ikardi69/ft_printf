/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sign_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:25:27 by mteffahi          #+#    #+#             */
/*   Updated: 2024/12/03 15:29:15 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"

int	ft_positive_sign(int nbr)
{
	int	size;

	size = 0;
	if (nbr < 0)
		size += ft_putnbr(nbr);
	else
		size += (ft_putchar('+') + ft_putnbr(nbr));
	return (size);
}
