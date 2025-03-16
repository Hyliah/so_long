/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <hlichten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 14:59:51 by hlichten          #+#    #+#             */
/*   Updated: 2025/03/16 19:35:46 by hlichten         ###   ########.fr       */
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

typedef	struct	s_mlx
{
	void	*mlx;
	void	*win;
	char	**map;
	char	*line;
	int		fd;
	int		sizeof_line; //13
	int		line_count; //5
}	t_mlx;


int	is_ber(char *arg, char *compaare);

#endif