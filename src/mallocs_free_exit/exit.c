/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <hlichten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 17:05:45 by hlichten          #+#    #+#             */
/*   Updated: 2025/03/21 19:33:50 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void print_map(t_mlx *mlx, char **map)
// {
// 	int i;

// 	i = 0;
// 	printf("\n");
// 	while (i < mlx->map.row)
// 		printf("%s\n", map[i++]);
// }

int clean_exit(t_graphic *graphic)
{
	//free_all
	mlx_destroy_window(graphic->mlx_ptr, graphic->win_ptr);
	exit (EXIT_SUCCESS);
}
