/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr_size_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 02:57:19 by mteffahi          #+#    #+#             */
/*   Updated: 2024/12/07 16:32:38 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"

int	ft_nbr_size(int nbr)
{
	int	i;

	i = 0;
	if (nbr == 0)
		return (1);
	else if (nbr < 0)
		i += 1;
	while (nbr != 0)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}
