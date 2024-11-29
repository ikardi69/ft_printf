/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 03:24:17 by mteffahi          #+#    #+#             */
/*   Updated: 2024/11/29 03:26:43 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"

int	ft_hexa_size(unsigned int value)
{
	int	size;

	size = 0;
	if (value == 0)
		return (1);
	while (value != 0)
	{
		value /= 16;
		size ++;
	}
	return (size);
}