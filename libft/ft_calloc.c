/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft _calloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 20:03:28 by hlichten          #+#    #+#             */
/*   Updated: 2024/10/19 18:40:43 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned int	i;
	char			*str;

	i = count * size;
	str = (char *)malloc(sizeof(char) * (i));
	if (!str)
		return (NULL);
	ft_bzero(str, i);
	return (str);
}
