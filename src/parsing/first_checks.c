/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <hlichten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 19:03:17 by hlichten          #+#    #+#             */
/*   Updated: 2025/03/27 17:13:05 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_ber(char *arg, char *compaare)
{
	int	len;
	int	i;

	i = 0;
	len = ft_strlen(arg) - 4;
	while (i < 4)
	{
		if (arg[len] == compaare[i])
		{
			len++;
			i++;
		}
		else
			return (0);
	}
	return (1);
}

int	check_char(char *arg, t_inputs *inputs, int col)
{
	int	i;

	i = 0;
	while (i < col)
	{
		if (arg[i] != '1' && arg[i] != '0' && arg[i] != 'C'
			&& arg[i] != 'E' && arg[i] != 'P')
			return (0);
		if (arg[i] == 'E')
			inputs->check_e++;
		if (arg[i] == 'P')
			inputs->check_p++;
		if (arg[i] == 'C')
			inputs->check_c++;
		i++;
	}
	return (1);
}

int	is_rectangle(t_inputs *inputs, int col, int check)
{
	if (check == col)
		return (1);
	if (check == col + 1)
	{
		if (inputs->line[col] == '\n')
			return (1);
		else
			return (0);
	}
	return (0);
}

int	first_check(t_mlx *mlx, char *arg)
{
	mlx->inputs.fd = open(arg, O_RDONLY);
	if (mlx->inputs.fd == -1)
		return (ft_putstr_fd(ERR_FD, 2), 1);
	if (!(is_ber(arg, ".ber")))
		return (ft_putstr_fd(ERR_FI, 2), 1);
	mlx->inputs.line = get_next_line(mlx->inputs.fd);
	if (!mlx->inputs.line)
		return (ft_putstr_fd(ERR_FD, 2), 1);
	mlx->map.col = ft_strlen(mlx->inputs.line) - 1;
	if (!check_char(mlx->inputs.line, &mlx->inputs, mlx->map.col))
		return (free(mlx->inputs.line), ft_putstr_fd(ERR_MA, 2), 1);
	free(mlx->inputs.line);
	while (1)
	{
		mlx->inputs.line = get_next_line(mlx->inputs.fd);
		if (mlx->inputs.line == NULL)
			break ;
		mlx->map.check = ft_strlen(mlx->inputs.line);
		if (is_rectangle(&mlx->inputs, mlx->map.col, mlx->map.check)
			&& (!check_char(mlx->inputs.line, &mlx->inputs, mlx->map.col)))
			return (free(mlx->inputs.line), ft_putstr_fd(ERR_MA, 2), 1);
		mlx->map.row++;
		free(mlx->inputs.line);
	}
	return (0);
}
