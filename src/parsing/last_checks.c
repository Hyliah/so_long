/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_checks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 16:34:10 by hlichten          #+#    #+#             */
/*   Updated: 2025/03/25 00:08:00 by hlichten         ###   ########.fr       */
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
		if (i != mlx->map.row)
			if (mlx->map.map_tab[i][0] != '1'
				|| mlx->map.map_tab[i][mlx->map.col - 1] != '1')
				return (1);
		i++;
	}
	return (0);
}

void	pos_player(t_mlx *mlx)
{
	int	x;
	int	y;

	y = 0;
	while (y < mlx->map.row)
	{
		x = 0;
		while (x < mlx->map.col)
		{
			if (mlx->map.map_tab[y][x] == 'P')
			{
				mlx->map.player.pos_x = x;
				mlx->map.player.pos_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

int	check_path(t_mlx *mlx)
{
	int		check_c;
	int		check_e;
	int		x;
	int		y;
	char	**new_map;

	x = mlx->map.player.pos_x;
	y = mlx->map.player.pos_y;
	new_map = cpy_map(mlx);
	check_e = rec_count(new_map, x, y, 'E');
	free_tab(mlx, new_map);
	if (check_e != 1)
		return (1);
	new_map = cpy_map(mlx);
	check_c = rec_count(new_map, x, y, 'C') - 1;
	free_tab(mlx, new_map);
	if (check_c != mlx->inputs.check_c)
		return (1);
	return (0);
}

int	rec_count(char **map_tab, int x, int y, char c)
{
	static int	count = 0;

	if (map_tab[y][x] == '1' || map_tab[y][x] == '*')
		return (count);
	if (map_tab[y][x] == c)
		count++;
	if (map_tab[y][x] != '1')
		map_tab[y][x] = '*';
	rec_count(map_tab, x + 1, y, c);
	rec_count(map_tab, x - 1, y, c);
	rec_count(map_tab, x, y + 1, c);
	rec_count(map_tab, x, y - 1, c);
	return (count);
}

int	check_count(t_mlx *mlx)
{
	if (mlx->inputs.check_c < 1)
		return (0);
	if (mlx->inputs.check_p != 1)
		return (0);
	if (mlx->inputs.check_e != 1)
		return (0);
	return (1);
}
