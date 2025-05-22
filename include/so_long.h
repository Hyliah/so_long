/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <hlichten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 14:59:51 by hlichten          #+#    #+#             */
/*   Updated: 2025/03/27 17:12:10 by hlichten         ###   ########.fr       */
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
# include "keycodes.h"

# define ERR_FI	"Error : non valid file\n"
# define ERR_PA	"Error : non valid path\n"
# define ERR_DB	"Error : non valid number of player, collectible or exit\n"
# define ERR_MA	"Error : non valid map\n"
# define ERR_FD	"Error : non valid file desctriptor\n"
# define ERR_CH	"Error : non valid character\n"
# define WA "./src/images/SL_1.xpm"
# define PA "./src/images/SL_0.xpm"
# define PL "./src/images/SL_Player.xpm"
# define EX "./src/images/SL_Exit.xpm"
# define CO "./src/images/SL_Collectible.xpm"

typedef struct s_graphic
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ex;
	void	*img_wa;
	void	*img_pl;
	void	*img_pa;
	void	*img_co;
	int		s_width;
	int		s_height;
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
	int		collected;
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

int		check_path(t_mlx *mlx);
int		last_check(t_mlx *mlx);
int		check_wall(t_mlx *mlx);
int		clean_exit(t_mlx *mlx);
int		check_count(t_mlx *mlx);
int		check_count(t_mlx *mlx);
int		is_ber(char *arg, char *compaare);
int		first_check(t_mlx *mlx, char *arg);
int		handle_key(int keycode, t_mlx *mlx);
int		rec_count(char **map_tab, int x, int y, char c);
int		check_char(char *arg, t_inputs *inputs, int col);
int		is_rectangle(t_inputs *inputs, int col, int check);

void	pos_player(t_mlx *mlx);
void	create_window(t_mlx *mlx);
void	malloc_map(char *arg, t_mlx *mlx);
void	will_move(t_mlx *mlx, int new_x, int new_y);
void	create_board(t_graphic *graphic, t_map *map);
void	move_player(t_mlx *mlx, int new_x, int new_y);
void	create_tile(t_graphic *graphic, char c, int size_x, int size_y);
#endif