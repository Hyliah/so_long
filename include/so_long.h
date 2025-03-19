/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <hlichten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 14:59:51 by hlichten          #+#    #+#             */
/*   Updated: 2025/03/19 19:08:37 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "ft_printf.h"
# include "libft.h"

typedef	struct	s_inputs
{
	int		fd;
	char	*line;
	int		check_p;
	int		check_e;
	int		check_c;
}	t_inputs;

typedef	struct	s_map
{
	int	col; // nb de colonnes -> strlen de la string
	int	check;
	int	row; //nb de lignes
	char **map_tab;
}	t_map;

typedef	struct	s_graphic
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
}	t_graphic;

typedef	struct	s_mlx
{
	t_map		map;
	t_inputs	inputs;
	t_graphic	graphic;
}	t_mlx;


int	last_check(t_mlx *mlx);
int check_wall(t_mlx *mlx);
int	check_count(t_mlx *mlx);
//int check_path(t_mlx *mlx);
int	is_ber(char *arg, char *compaare);
int	first_check(t_mlx  *mlx, char *arg);
int	check_char(char *arg, t_inputs *inputs, int col);
int	is_rectangle(t_inputs *inputs, int col, int check);


#endif