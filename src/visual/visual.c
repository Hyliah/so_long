/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <hlichten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 18:29:08 by hlichten          #+#    #+#             */
/*   Updated: 2025/03/26 15:55:41 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_tile(t_graphic *graphic, char c, int size_x, int size_y)
{
	if (c == '1')
		mlx_put_image_to_window(graphic->mlx_ptr, graphic->win_ptr,
			graphic->img_wa, size_x, size_y);
	if (c == '0')
		mlx_put_image_to_window(graphic->mlx_ptr, graphic->win_ptr,
			graphic->img_pa, size_x, size_y);
	if (c == 'E')
		mlx_put_image_to_window(graphic->mlx_ptr, graphic->win_ptr,
			graphic->img_ex, size_x, size_y);
	if (c == 'C')
		mlx_put_image_to_window(graphic->mlx_ptr, graphic->win_ptr,
			graphic->img_co, size_x, size_y);
	if (c == 'P')
		mlx_put_image_to_window(graphic->mlx_ptr, graphic->win_ptr,
			graphic->img_pl, size_x, size_y);
}

void	create_board(t_graphic *graphic, t_map *map)
{
	int	i;
	int	j;
	int	x;
	int	y;

	x = 64;
	y = 64;
	i = 0;
	graphic->img_co = mlx_xpm_file_to_image(graphic->mlx_ptr, CO, &x, &y);
	graphic->img_pl = mlx_xpm_file_to_image(graphic->mlx_ptr, PL, &x, &y);
	graphic->img_wa = mlx_xpm_file_to_image(graphic->mlx_ptr, WA, &x, &y);
	graphic->img_pa = mlx_xpm_file_to_image(graphic->mlx_ptr, PA, &x, &y);
	graphic->img_ex = mlx_xpm_file_to_image(graphic->mlx_ptr, EX, &x, &y);
	while (map->map_tab[i])
	{
		j = 0;
		while (map->map_tab[i][j])
		{
			create_tile(graphic, map->map_tab[i][j], j * 64, i * 64);
			j++;
		}
		i++;
	}
}

void	create_window(t_mlx *mlx)
{
	int	x;
	int	y;

	x = 64 * mlx->map.col;
	y = 64 * mlx->map.row;
	mlx->graphic.mlx_ptr = mlx_init();
	mlx->graphic.win_ptr = mlx_new_window(mlx->graphic.mlx_ptr, x, y, "Poups");
	create_board(&mlx->graphic, &mlx->map);
	mlx_hook(mlx->graphic.win_ptr, 17, 0, clean_exit, &mlx);
}
