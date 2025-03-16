/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <hlichten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 15:01:14 by hlichten          #+#    #+#             */
/*   Updated: 2025/03/16 19:19:04 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_mlx	mlx;
	// int		i;

	// i = 0;
	if (ac == 2)
	{
		// chekc extension du fichier .ber
		mlx.fd = open(av[1], O_RDONLY);
		if(mlx.fd == -1)
			return (perror("Error"), 1);
		while (1)
		{
			mlx.line = get_next_line(mlx.fd);
			if (is_ber(av[1], ".ber"))
				printf("yay is ber\n");
			if(mlx.line == NULL)
				break;
			printf("%s", mlx.line);
		}

		// if(checks(mlx.line) == ok)
		// // 	mlx.map = line;
	}

	return (0);
}