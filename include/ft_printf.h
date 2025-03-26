/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 15:48:32 by hlichten          #+#    #+#             */
/*   Updated: 2024/11/11 16:03:22 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
void	ft_putchar_count(char c, int *count);
void	ft_putstr_count(char *s, int *count);
void	ft_putnbr_count(int n, int *count);
void	ft_puthexa_count(unsigned long n, int *count, char type);
void	ft_putunsigned_count(unsigned int n, int *count);
void	handle_char(va_list argument, int *count);
void	handle_string(va_list argument, int *count);
void	handle_pointer(va_list argument, int *count);
void	handle_integer(va_list argument, int *count);
void	handle_unsigned(va_list argument, int *count);
void	handle_lower_hexa(va_list argument, int *count);
void	handle_upper_hexa(va_list argument, int *count);
void	handle_modulo(int *count);

#endif