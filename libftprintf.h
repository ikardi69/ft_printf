/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 00:56:20 by mteffahi          #+#    #+#             */
/*   Updated: 2024/11/22 23:40:37 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF
# define LIBFTPRINTF

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *, ...);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_printf_adress(void	*ptr);
int	ft_putnbr(int n, int *size);

#endif