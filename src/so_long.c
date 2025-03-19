/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <hlichten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 15:01:14 by hlichten          #+#    #+#             */
/*   Updated: 2025/03/19 19:07:39 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	malloc_map(char *arg, t_mlx *mlx)
{
	int	i;

	i = 0;
	mlx->map.map_tab = malloc(sizeof(char *) * (mlx->map.row + 1));
	if (!mlx->map.map_tab)
		return (perror("Error: malloc failed"));
	mlx->inputs.fd = open(arg, O_RDONLY);
	if(mlx->inputs.fd == -1)
		return (ft_putstr_fd("Error : incorrect fd\n", 2));
	while(i < mlx->map.row)
	{
		mlx->inputs.line = get_next_line(mlx->inputs.fd);
		if (mlx->inputs.line == NULL)
			break;
		mlx->map.map_tab[i] = ft_strndup(mlx->inputs.line, mlx->map.col);
		printf("%s\n", mlx->map.map_tab[i]); // test a supprimer
		free (mlx->inputs.line);
		i++;
	}
	mlx->map.map_tab[i] = NULL;
	close(mlx->inputs.fd);
}

void	mlx_init(t_mlx *mlx)
{
	mlx->map.col = 0;
	mlx->map.row = 1;
	mlx->inputs.fd = -1;
	mlx->map.map_tab = 0;
	mlx->inputs.line = 0;
	mlx->inputs.check_c = 0;
	mlx->inputs.check_p = 0;
	mlx->inputs.check_e = 0;
	mlx->graphic.mlx_ptr = 0;
	mlx->graphic.win_ptr = 0;
	mlx->graphic.img_ptr = 0;
}


int	main(int ac, char **av)
{
	t_mlx	mlx;

	mlx_init(&mlx);
	if (ac == 2)
	{
		if (first_check(&mlx, av[1]) == 1)
			return (1);
		if (!check_count(&mlx))
			return (ft_putstr_fd("Error : incorrect element\n", 2), 1);
		close(mlx.inputs.fd);
		malloc_map(av[1], &mlx);
		if (last_check(&mlx) == 1)
			{
				//free_tab(); //creer fonction
				return (ft_putstr_fd("Error : incorrect map\n", 2), 1);
			}
		else {} 
			//lets gooooooooooooo;




	}
	return (0);
}


		// n * 16 (ou taille de tile);
		//refresh texture la ou le joeur va. 
		// si appuyer en haut, on de place la texture vers le haut aka P,
			//et mettre un 0 derrire lui et on refresh juste ces 2 tiles la
		//commentaire la maintentant 