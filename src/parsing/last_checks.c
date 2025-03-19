/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_checks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <hlichten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 16:34:10 by hlichten          #+#    #+#             */
/*   Updated: 2025/03/19 19:05:42 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_wall(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	while (i < mlx->map.row)
	{
		j = 0;
		if (i == 0 || (i == mlx->map.row - 1))
		{
			while (j < mlx->map.col)
			{				
				if (mlx->map.map_tab[i][j] == '1')
					j++;
				else 
					return (1);
			}
			i++;
		}
		if (i == 5)
			return (0);
		if (mlx->map.map_tab[i][0] != '1' || mlx->map.map_tab[i][mlx->map.col - 1] != '1')
			return (1);
		i++;
	}
	return (0);
}

// int check_path(char *mlx) // flood_fill
// {

// 	return (0);
// }


int	check_count(t_mlx *mlx)
{
	if (mlx->inputs.check_c < 1)
		return (0);
	else if (mlx->inputs.check_p != 1)
		return (0);
	if (mlx->inputs.check_e != 1)
		return (0);
	return (1);
}

int	last_check(t_mlx *mlx)
{
	//check_path(&mlx); // creer fonction
	if (check_wall(mlx) == 1)
		return (ft_putstr_fd("Error : incorrect walls\n", 2), 1);
	return (0);
}