/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 17:31:05 by hlichten          #+#    #+#             */
/*   Updated: 2024/10/19 18:49:20 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr(unsigned int n, char *array, int i)
{
	if (n > 9)
		ft_putnbr(n / 10, array, i - 1);
	array[i - 1] = (n % 10) + '0';
}

static int	ft_nblen(int nbr)
{
	unsigned int	n;
	int				len;

	len = 1;
	if (nbr < 0)
	{
		n = nbr * -1;
		len ++;
	}
	else
		n = nbr;
	while (n > 9)
	{
		n /= 10;
		len ++;
	}
	return (len);
}

char	*ft_itoa(int nbr)
{
	char			*str;
	int				len;
	unsigned int	n;

	len = ft_nblen(nbr);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (nbr < 0)
	{
		n = nbr * -1;
		str[0] = '-';
	}
	else
		n = nbr;
	str[len] = 0;
	ft_putnbr(n, str, len);
	return (str);
}

// #include <stdlib.h>
// #include <stdio.h>
// int main(int ac, char **av)
// {
//     (void)ac;
//     (void)av;
//     char *tmp;

//     tmp = ft_itoa(-0x80000000);
//     printf("%s\n", tmp);
//     free(tmp);
// }
