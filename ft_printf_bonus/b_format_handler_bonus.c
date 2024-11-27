/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_format_handler_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 02:43:51 by mteffahi          #+#    #+#             */
/*   Updated: 2024/11/27 21:48:00 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"

int	ft_bonus_format_handler(va_list args, const char *s)
{
	int size;

	size = 0;
	if (s[size] == '.')
	{
		//s++;
		size += ft_dot(args, s+1);
	}
	return (size);
}
