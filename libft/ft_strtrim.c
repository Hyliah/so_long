/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 20:23:05 by hlichten          #+#    #+#             */
/*   Updated: 2024/10/20 17:45:45 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" //fonctionne pas

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	int		x;
	int		y;

	if (!set || !s1)
		return (NULL);
	x = 0;
	y = ft_strlen((char *)s1);
	while (s1[x] && ft_strchr(set, s1[x]))
		x++;
	while (y > x && ft_strchr(set, s1[y]))
		y--;
	trim = ft_substr((char *)(s1 + x), 0, (y - x + 1));
	return (trim);
}
/*
#include <stdio.h>
int main(int ac, char **av)
{
    (void)ac;
    printf("%s", ft_strtrim(av[1], av[2]));
}*/
