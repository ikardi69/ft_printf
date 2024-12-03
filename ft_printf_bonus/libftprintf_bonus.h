/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 00:56:20 by mteffahi          #+#    #+#             */
/*   Updated: 2024/12/03 11:10:15 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_BONUS_H
# define LIBFTPRINTF_BONUS_H

# include <unistd.h>
# include <stdarg.h>
# include <libc.h>

# define LL_MAX 9223372036854775807LL

int	ft_printf(const char *, ...);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_printf_ptr_adress(void	*ptr);
int	ft_putnbr(int n);
int	ft_put_unsigned(unsigned int n);
int	ft_putnbr_hex_low(unsigned int nbr);
int	ft_putnbr_hex_up(unsigned int);
int	ft_bonus_format_handler(va_list args, const char *s);
int	ft_nbr_size(int nbr);
int	ft_skip(const char *s);
int	ft_atoi(const char *str);
int	ft_putstr_precision(const char *s, int precision);
int	ft_dot(va_list args, const char *s);
int	ft_negative_handle(va_list args, const char *s);
int	ft_zero_padding(va_list args, const char *s);
int	ft_hexa_size(unsigned int value);
int	ft_field_minimum_width(va_list args, const char *s);
int	format_handler(va_list args, const char s);
int	ft_strlen(char *s);
int	ft_hash(va_list args, const char *s);

#endif