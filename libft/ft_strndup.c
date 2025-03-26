/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <hlichten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 21:16:11 by hlichten          #+#    #+#             */
/*   Updated: 2025/03/05 21:16:33 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *src, int n)
{
	char	*dest;

	dest = (char *) malloc(sizeof(char) * (n + 1));
	if (dest == NULL)
		return (NULL);
	ft_strlcpy(dest, src, n + 1);
	return (dest);
}
