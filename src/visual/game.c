/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <hlichten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:13:30 by hlichten          #+#    #+#             */
/*   Updated: 2025/03/26 18:09:29 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_key(int keycode, t_mlx *mlx)
{
	if (keycode == KEY_A || keycode == KEY_LEFTARROW)
		will_move(mlx, mlx->map.player.pos_x - 1, mlx->map.player.pos_y);
	if (keycode == KEY_D || keycode == KEY_RIGHTARROW)
		will_move(mlx, mlx->map.player.pos_x + 1, mlx->map.player.pos_y);
	if (keycode == KEY_W || keycode == KEY_UPARROW)
		will_move(mlx, mlx->map.player.pos_x, mlx->map.player.pos_y - 1);
	if (keycode == KEY_S || keycode == KEY_DOWNARROW)
		will_move(mlx, mlx->map.player.pos_x, mlx->map.player.pos_y + 1);
	if (keycode == KEY_ESCAPE)
		clean_exit(mlx);
	return (0);
}
void	count_move(void)
{
	static int count = 0;

}
void	will_move(t_mlx *mlx, int new_x, int new_y)
{
	if (mlx->map.map_tab[new_y][new_x] != '1')
	{
		if (mlx->map.map_tab[new_y][new_x] == 'C')
		{
			mlx->map.map_tab[new_y][new_x] = '0';
			move_player(mlx, new_x, new_y);
			mlx->inputs.collected++;
		}
		if (mlx->map.map_tab[new_y][new_x] == '0'
			|| mlx->map.map_tab[new_y][new_x] == 'P')
			move_player(mlx, new_x, new_y);
		if (mlx->map.map_tab[new_y][new_x] == 'E')
		{
			if (mlx->inputs.collected == mlx->inputs.check_c)
				clean_exit(mlx);
			else
			{
				move_player(mlx, new_x, new_y);
				return ;
			}
		}
		//cnt++;
	}
}

void	move_player(t_mlx *mlx, int new_x, int new_y)
{
	if (mlx->map.map_tab[mlx->map.player.pos_y][mlx->map.player.pos_x] == 'E')
		create_tile(&mlx->graphic, 'E', mlx->map.player.pos_x * 64,
			mlx->map.player.pos_y * 64);
	else
		create_tile(&mlx->graphic, '0', mlx->map.player.pos_x * 64,
			mlx->map.player.pos_y * 64);
	create_tile(&mlx->graphic, 'P', new_x * 64, new_y * 64);
	mlx->map.player.pos_x = new_x;
	mlx->map.player.pos_y = new_y;
}
