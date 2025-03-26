/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <hlichten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 15:01:14 by hlichten          #+#    #+#             */
/*   Updated: 2025/03/26 16:39:23 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mlx_init_sl(t_mlx *mlx)
{
	mlx->map.col = 0;
	mlx->map.row = 1;
	mlx->inputs.fd = -1;
	mlx->map.map_tab = 0;
	mlx->inputs.line = 0;
	mlx->inputs.check_c = 0;
	mlx->inputs.check_p = 0;
	mlx->inputs.check_e = 0;
	mlx->inputs.collected = 0;
	mlx->graphic.mlx_ptr = 0;
	mlx->graphic.win_ptr = 0;
	mlx->graphic.img_pa = 0;
	mlx->graphic.img_co = 0;
	mlx->graphic.img_wa = 0;
	mlx->graphic.img_pl = 0;
	mlx->graphic.img_ex = 0;
}

int	last_check(t_mlx *mlx)
{
	if (check_wall(mlx) == 1)
		return (ft_putstr_fd("Error\n", 2), 1);
	pos_player(mlx);
	if (check_path(mlx) == 1)
		return (ft_putstr_fd("Error\n", 2), 1);
	return (0);
}

int	main(int ac, char **av)
{
	t_mlx		mlx;

	mlx_init_sl(&mlx);
	if (ac == 2)
	{
		if (first_check(&mlx, av[1]) == 1)
			return (1);
		if (!check_count(&mlx))
			return (ft_putstr_fd("Error\n", 2), 1);
		close(mlx.inputs.fd);
		malloc_map(av[1], &mlx);
		if (last_check(&mlx) == 1)
			return (free_tab(&mlx, mlx.map.map_tab), 1);
		create_window(&mlx);
		mlx_key_hook(mlx.graphic.win_ptr, handle_key, &mlx);
		mlx_loop(mlx.graphic.mlx_ptr);
	}
	return (0);
}
