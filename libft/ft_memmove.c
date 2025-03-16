/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 17:42:21 by hlichten          #+#    #+#             */
/*   Updated: 2024/10/19 19:01:56 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*d;
	const char	*s;

	if (!dst && !src)
		return (NULL);
	d = (char *)dst;
	s = (const char *)src;
	if (src > dst)
		return (ft_memcpy(dst, src, len));
	if (src < dst)
	{
		while (len > 0)
		{
			len--;
			d[len] = s[len];
		}
	}
	return (dst);
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// int main(int ac, char **av)
// {
//     (void)ac;
// 	(void)av;
// 	char data[] = "1234567890";
// 	char data1[] = "1234567890";
//     memmove(data + 2, data + 2, 5);
// 	ft_memmove(data1 + 2, data1 + 2, 5);
//     printf("Résultat avec memmove: %s\n", data);
// 	printf("Résultat avec ft_memmove: %s\n", data1);
// 	return (0);
// }