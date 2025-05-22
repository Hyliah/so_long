/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 17:05:45 by hlichten          #+#    #+#             */
/*   Updated: 2025/05/23 00:03:31 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	clean_exit(t_mlx *mlx)
{
	mlx_destroy_image(mlx->graphic.mlx_ptr, mlx->graphic.img_wa);
	mlx_destroy_image(mlx->graphic.mlx_ptr, mlx->graphic.img_pa);
	mlx_destroy_image(mlx->graphic.mlx_ptr, mlx->graphic.img_co);
	mlx_destroy_image(mlx->graphic.mlx_ptr, mlx->graphic.img_pl);
	mlx_destroy_image(mlx->graphic.mlx_ptr, mlx->graphic.img_ex);
	mlx_destroy_window(mlx->graphic.mlx_ptr, mlx->graphic.win_ptr);
	mlx_destroy_display(mlx->graphic.mlx_ptr);
	free(mlx->graphic.mlx_ptr);
	mlx->graphic.mlx_ptr = NULL;
	free_tab(mlx, mlx->map.map_tab);
	exit (EXIT_SUCCESS);
}
