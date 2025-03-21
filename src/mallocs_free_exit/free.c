/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <hlichten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 17:05:42 by hlichten          #+#    #+#             */
/*   Updated: 2025/03/21 17:24:34 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**free_mid_tab(char **strs, int i)
{
	while (i > 0)
	{
		i--;
		free (strs[i]);
	}
	free(strs);
	return (NULL);
}

char	**free_tab(t_mlx *mlx, char **tab)
{
	int	i;

	i = 0;
	while (i < mlx->map.row)
	{
		free (tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}
