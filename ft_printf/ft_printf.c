/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <hlichten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 15:22:38 by hlichten          #+#    #+#             */
/*   Updated: 2025/03/26 18:01:16 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_format(char c, va_list argument, int *count)
{
	if (c == 'p')
		handle_pointer(argument, count);
	if (c == 'x')
		handle_lower_hexa(argument, count);
	if (c == 'X')
		handle_upper_hexa(argument, count);
	if (c == '%')
		handle_modulo(count);
	if (c == 'u')
		handle_unsigned(argument, count);
	if (c == 'c')
		handle_char(argument, count);
	if (c == 's')
		handle_string(argument, count);
	if (c == 'd')
		handle_integer(argument, count);
	if (c == 'i')
		handle_integer(argument, count);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		j;
	int		*count;
	va_list	argument;

	i = 0;
	j = 0;
	count = &j;
	va_start(argument, format);
	while (format[i])
	{
		if (format[i] != '%')
		{
			ft_putchar_count(format[i], count);
		}
		else
		{
			i++;
			handle_format(format[i], argument, count);
		}
		i++;
	}
	va_end(argument);
	return (*count);
}

// #include <stdlib.h>
// #include <stdio.h>

// int	main (void)
// {
// 	printf("return len from ft_printf is %d\n", ft_printf("%%%c ", 'a'));
// 	printf("return len from printf is %d\n", printf("%%%c ", 'a'));
// 	return (0);
// }
