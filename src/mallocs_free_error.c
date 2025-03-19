/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mallocs_free_error.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <hlichten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 15:29:09 by hlichten          #+#    #+#             */
/*   Updated: 2025/03/19 22:06:46 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**free_mid_tab(char **strs, int i)
{
	while (i > 0)
	{
		i--;
		free (strs[i]);
	}
	free(strs);
	return (NULL);
}

char	**free_tab(t_mlx *mlx, char **tab)
{
	int i;

	i = 0;
	while (i < mlx->map.row)
	{
		free (tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

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
		if (mlx->map.map_tab[i] == NULL)
			free_mid_tab(mlx->map.map_tab, i);
		printf("%s\n", mlx->map.map_tab[i]); // test a supprimer
		free (mlx->inputs.line);
		i++;
	}
	mlx->map.map_tab[i] = NULL;
	close(mlx->inputs.fd);
}

char	**cpy_map(t_mlx *mlx)
{
	int		i;
	char	**cpy_map;
	
	i = 0;
	cpy_map = malloc(sizeof(char *) * (mlx->map.row + 1));
	if(!cpy_map)
		return (NULL);
	while (i < mlx->map.row)
	{
		cpy_map[i] = ft_strdup(mlx->map.map_tab[i]);
		if (cpy_map[i] == NULL)
			free_mid_tab(cpy_map, i);
		i++;
	}
	cpy_map[i] = 0;
	return(cpy_map);
}
// void print_map(t_mlx *mlx, char **map)
// {
// 	int i;

// 	i = 0;
// 	printf("\n");
// 	while (i < mlx->map.row)
// 		printf("%s\n", map[i++]);
// }