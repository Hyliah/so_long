/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <hlichten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:21:57 by hlichten          #+#    #+#             */
/*   Updated: 2025/03/26 14:51:53 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_free(char **line)
{
	free(*line);
	*line = NULL;
	return (NULL);
}

int	join_and_check(char **line, char *to_join)
{
	char	*temp;

	temp = ft_strjoin_free(*line, to_join);
	if (!temp)
		return (1);
	*line = temp;
	return (0);
}

int	update_and_check(char *buffer, char **line)
{
	char	*newline;

	newline = ft_strchr(buffer, '\n');
	if (newline != NULL)
	{
		*newline = '\0';
		if (join_and_check(line, buffer) || join_and_check(line, "\n"))
			return (0);
		ft_strlcpy(buffer, newline + 1, BUFFER_SIZE - (newline - buffer));
		return (1);
	}
	if (join_and_check(line, buffer))
		return (0);
	buffer[0] = '\0';
	return (0);
}

int	is_eof(int rd, char *buffer, char **line)
{
	if (rd < 0)
		return (1);
	if (rd == 0 && !*line && buffer[0] == '\0')
		return (1);
	return (0);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1] = {0};
	char		*line;
	int			rd;

	rd = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	while (1)
	{
		if (buffer[0] == '\0')
		{
			rd = read(fd, buffer, BUFFER_SIZE);
			if (rd >= 0)
				buffer[rd] = '\0';
			if (is_eof(rd, buffer, &line))
				return (ft_free(&line));
		}
		if (update_and_check(buffer, &line))
			return (line);
		if (rd == 0)
			break ;
	}
	return (line);
}

// # include <stdio.h> 
// # include <stdio.h>
// # include <fcntl.h>

// int    main (int ac, char **av)
// {
//     int     fd;
//     char    *line;

//     fd = open(*(++ av), O_RDONLY);
//     while ((line = get_next_line(fd)) != NULL)
//     {
//         printf("%s", line);
//         free (line);
//     }
// 	return 0;
// }