/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 00:56:20 by mteffahi          #+#    #+#             */
/*   Updated: 2025/01/15 18:40:42 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
#include <stdio.h>

# define LL_MAX 9223372036854775807LL

int		ft_printf(const char *s, ...);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_printf_ptr_adress(void	*ptr);
int		ft_putnbr(int n);
int		ft_put_unsigned(unsigned int n);
int		ft_putnbr_hex_low(unsigned int nbr);
int		ft_putnbr_hex_up(unsigned int nbr);
int		ft_bonus_format_handler(va_list args, const char *s);
int		ft_nbr_size(int nbr);
int		ft_skip(const char *s);
int		ft_atoi(const char *str);
int		ft_putstr_precision(const char *s, int precision);
int		ft_dot(va_list args, const char *s);
int		ft_negative_handle(va_list args, const char *s);
int		ft_zero_padding(va_list args, const char *s);
int		ft_hexa_size(unsigned int value);
int		ft_field_minimum_width(va_list args, const char *s);
int		format_handler(va_list args, const char s);
int		ft_strlen(char *s);
int		ft_hash(va_list args, const char *s);
int		ft_space_handler(int nbr);
int		ft_positive_sign(int nbr);
int		ft_combination1(va_list args, const char *s);
int		ft_combination2(va_list args, const char*s);
int		ft_skip_pf(const char *s);
int		ft_combination3(va_list args, const char *s);
void	ft_handle_integer(const char *s, va_list args, int *size,
			unsigned long long *tmp);
void	ft_handle_str(const char *s, va_list args, int *size);
void	ft_handle_ptr(const char *s, va_list args, int *size,
			unsigned long long *tmp);
int		ft_put(int tmp, int precision);
int		ft_put_char_precision(va_list args, int precision);
int		ft_putstr_negative(va_list args, int precision);
int		ft_unsigned_precision(va_list args, int precision);
int		ft_int_precision(va_list args, int flag, int precision);
int		ft_hex_low_dot(unsigned int nbr, int precision);
int		ft_hex_up_dot(unsigned int nbr, int precision);
int		ft_check_tmp_int(long *tmp);
int		ft_put_unsigned_nbr(unsigned int n);
int		ft_nbr_unsigned_size(unsigned int nbr);
int		ft_size_t_putnbr(size_t n);
int		ft_size_t_precision(size_t nbr, int precision);
int		ft_nbr_size_t(size_t nbr);
int		ft_space_p(unsigned int nbr, int width);
int		ft_put_llu(unsigned long long tmp, int precision);
int		ft_hexa_ptr_size(unsigned long long value);
int		ft_unsigned_negative(unsigned int nbr, int precision);
int		ft_hex_low_neg(unsigned int nbr, int precision);
int		ft_hex_upp_neg(unsigned int nbr, int precision);
int		ft_putnbr_always_positive(long n);
int		ft_negative_zpadding_helper(int tmp);
int		ft_hash_helper(unsigned int tmp);

#endif