/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 22:16:35 by hlichten          #+#    #+#             */
/*   Updated: 2024/10/19 18:31:51 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int	i;
	int	nb;
	int	neg;

	i = 0;
	nb = 0;
	neg = 1;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == 45 || str[i] == 43)
	{
		if (str[i] == '-')
		{
			neg = -neg;
		}
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = (nb * 10) + (str[i] - 48);
		i++;
	}
	return (nb * neg);
}

// #include <stdio.h>
// #include <stdlib.h>
// int main(int ac, char **av)
// {
//     (void)ac;
//     printf("%d \n", atoi(av[1]));
//     printf("%d \n", ft_atoi(av[1])); 
//     return 0;
// }
