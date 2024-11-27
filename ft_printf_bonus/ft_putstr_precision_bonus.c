/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_precision_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 03:39:18 by mteffahi          #+#    #+#             */
/*   Updated: 2024/11/27 03:41:00 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"

int	ft_putstr_precision(const char *s, int precision)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && i < precision)
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}