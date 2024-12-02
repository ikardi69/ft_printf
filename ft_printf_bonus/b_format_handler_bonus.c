/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_format_handler_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 02:43:51 by mteffahi          #+#    #+#             */
/*   Updated: 2024/12/02 14:33:03 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"

int	ft_bonus_format_handler(va_list args, const char *s)
{
	int size;

	size = 0;
	if (s[size] == '.')
		size += ft_dot(args, s+1);
	else if (s[size] == '-')
		size += ft_negative_handle(args, s+1);
	else if (s[size] == '0')
		size += ft_zero_padding(args, s+1);
	else if (s[size] >= '0' && s[size] <= '9')
		size += ft_field_minimum_width(args, s);
	return (size);
}
