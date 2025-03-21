/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <hlichten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 14:59:51 by hlichten          #+#    #+#             */
/*   Updated: 2025/03/21 19:37:02 by hlichten         ###   ########.fr       */
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
# include "mlx.h"
# include "mlx_int.h"

typedef struct s_graphic
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
}	t_graphic;

typedef struct s_player
{
	int	pos_x;
	int	pos_y;

}	t_player;

typedef struct s_map
{
	int			col;
	int			check;
	int			row;
	char		**map_tab;
	t_player	player;
}	t_map;

typedef struct s_inputs
{
	int		fd;
	char	*line;
	int		check_p;
	int		check_e;
	int		check_c;
}	t_inputs;

typedef struct s_mlx
{
	t_map		map;
	t_inputs	inputs;
	t_graphic	graphic;
}	t_mlx;

char	**cpy_map(t_mlx *mlx);
char	**free_tab(t_mlx *mlx, char **tab);
char	**free_mid_tab(char **strs, int i);

void	pos_player(t_mlx *mlx);
void	malloc_map(char *arg, t_mlx *mlx);
void	create_visual(void);
int		check_path(t_mlx *mlx);
int		last_check(t_mlx *mlx);
int		check_wall(t_mlx *mlx);
int		check_count(t_mlx *mlx);
int		check_count(t_mlx *mlx);
int		clean_exit(t_graphic *graphic);
int		is_ber(char *arg, char *compaare);
int		first_check(t_mlx *mlx, char *arg);
int		rec_count(char **map_tab, int x, int y, char c);
int		check_char(char *arg, t_inputs *inputs, int col);
int		is_rectangle(t_inputs *inputs, int col, int check);
#endif