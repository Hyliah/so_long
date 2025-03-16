/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <hlichten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 16:34:10 by hlichten          #+#    #+#             */
/*   Updated: 2025/03/16 19:14:08 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_ber(char *arg, char *compaare)
{
	int	len;
	int	i;

	i = 0;
	len = ft_strlen(arg) - 4;

	while(i < 4)
	{
		if (arg[len] == compaare[i])
		{
			len++;
			i++;
		}
		else
			return (0);
	}
	return (1);
}

int	check_wall(char *arg)
{

	return (0);
}

int check_general(char *arg)
{

	return (0);
}

int	check_double(char *arg);

int ft_firstest(char *arg)
{
	if (check_wall &&)
	return (0);
}