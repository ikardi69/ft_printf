/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_precision_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 03:39:18 by mteffahi          #+#    #+#             */
/*   Updated: 2024/11/27 17:51:52 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"

int	ft_putstr_precision(const char *s, int precision)
{
	int		i;
	char	*n;

	i = 0;
	if (!s)
	{
		n = "(null)";
		while (n[i] != '\0' && i < precision)
		{
			write(1, &n[i], 1);
			i++;
		}
		return (i);
	}
	while (s[i] != '\0' && i < precision)
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}
