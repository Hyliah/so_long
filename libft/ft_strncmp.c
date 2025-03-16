/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 18:52:27 by hlichten          #+#    #+#             */
/*   Updated: 2024/10/20 17:37:22 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!n)
		return (0);
	while (s1[i] && s2[i] && i < n - 1 && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

// #include "string.h"
// #include "stdio.h"
// #include "stdlib.h"
// int main(int ac, char **av)
// {
//     (void)ac;
//     printf("%d \n", ft_strncmp(av[1], av[2], atoi(av[3])));
//     printf("%d \n", strncmp(av[1], av[2], atoi(av[3])));
//     return 0;
// }
