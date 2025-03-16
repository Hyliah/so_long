/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <hlichten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 14:59:51 by hlichten          #+#    #+#             */
/*   Updated: 2025/03/16 22:43:01 by hlichten         ###   ########.fr       */
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
	char	*pathname;
	int		fd;
	char		*line;
}	t_inputs;

typedef	struct	s_map
{
	int	col;
	int	row;
	char **map;
}	t_map;

typedef	struct	s_graphic
{
	void	*mlx;
	void	*win;
	void	*img;
	//voir photo 16.03 pour si besoin
}	t_graphic;

typedef	struct	s_mlx
{
	t_map		map;
	t_inputs	inputs;
	t_graphic	graphic;
}	t_mlx;


int	is_ber(char *arg, char *compaare);

#endif