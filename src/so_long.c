/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <hlichten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 15:01:14 by hlichten          #+#    #+#             */
/*   Updated: 2025/03/16 22:46:44 by hlichten         ###   ########.fr       */
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
		mlx.inputs.fd = open(av[1], O_RDONLY);
		if(mlx.inputs.fd == -1)
			return (perror("Error"), 1);
		if (!(is_ber(av[1], ".ber")))
			return (ft_putstr_fd("Pas cool", STDERR_FILENO), 1);
		while (1)
		{
			mlx.inputs.line = get_next_line(mlx.inputs.fd);

			if(mlx.inputs.line == NULL)
				break;
			printf("%s", mlx.inputs.line);
		}

		// if(checks(mlx.line) == ok)
		// // 	mlx.map = line;
	}

	return (0);
}