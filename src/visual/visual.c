/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <hlichten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 18:29:08 by hlichten          #+#    #+#             */
/*   Updated: 2025/03/21 19:37:31 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_visual(void)//(t_mlx *mlx)
{
	t_graphic	graphic;

	graphic.mlx_ptr = mlx_init(); 
	// estabish a connection w server
	// aura besoinde free car il va malloquer la struct xvar
	// va creer une structure xvar et va la retourner

	graphic.win_ptr = mlx_new_window(graphic.mlx_ptr, 1920, 1080, "Poupou");
	// creation d une image, hardcode pour l instant de la taille, creer et maj les infos
	//
	graphic.img_ptr = mlx_new_image(graphic.mlx_ptr, 1920, 1080);
	mlx_hook(graphic.win_ptr, 17, 0, clean_exit, &graphic);
	mlx_loop(graphic.mlx_ptr);
}



// convertir en xpm depuis png

