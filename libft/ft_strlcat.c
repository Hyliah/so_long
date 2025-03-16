/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 19:49:52 by hlichten          #+#    #+#             */
/*   Updated: 2024/10/20 17:43:38 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;

	k = 0;
	while (dst[k] && k < dstsize)
		k++;
	if (dstsize <= k)
		return (dstsize + ft_strlen((char *) src));
	i = 0;
	j = k;
	while (src[i] && j < dstsize -1)
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (k + ft_strlen((char *) src));
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <bsd/string.h>
int main(int ac, char **av)
{
    (void)ac;
    printf("%lu \n", strlcat(av[1], av[2], atoi(av[3])));
    printf("%lu \n", ft_strlcat(av[4], av[5], atoi(av[6])));
}*/
