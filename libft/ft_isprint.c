/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 21:34:08 by hlichten          #+#    #+#             */
/*   Updated: 2024/10/19 18:44:17 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	if (c >= 32 && c < 127)
		return (1);
	return (0);
}

// #include <ctype.h>
// #include <stdio.h>
// #include <stdlib.h>
// int main(int ac, char **av)
// {
//     (void)ac;
//     printf("%d \n", isprint(atoi(av[1])));
//     printf("%d \n", ft_isprint(atoi(av[1]))); 
//     return 0;
// }
