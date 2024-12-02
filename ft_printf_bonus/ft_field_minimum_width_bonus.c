/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_field_minimum_width_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:29:45 by mteffahi          #+#    #+#             */
/*   Updated: 2024/12/02 16:42:46 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"

static int	padding(int w, int m)
{
	int	i;

	i = 0;
	while (i < w)
		i += write(1, " ", 1);
	return (i);
}
// type problem for padding
int	ft_field_minimum_width(va_list args, const char *s)
{
	int	width;
	int	size;
	int	i;
	int	m;

	width = ft_atoi(s);
	i = ft_skip(s);
	size = 0;
	if (s[i] == 'c')
		m += 1;
	else if (s[i] == 's')
	size += padding(width, m);
	size += format_handler(args, (const char)s+i);
	return (size);
}
