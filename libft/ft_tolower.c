/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 17:23:22 by hlichten          #+#    #+#             */
/*   Updated: 2024/10/19 19:03:31 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c += 32);
	return (c);
}
/*
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
int main(int ac, char **av)
{
    (void)ac;
    printf("%d \n", tolower(atoi(av[1])));
    printf("%d \n", ft_tolower(atoi(av[1])));
 
    return 0;
}*/
