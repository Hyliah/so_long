/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 20:59:08 by hlichten          #+#    #+#             */
/*   Updated: 2024/10/20 20:25:28 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static char	**ft_free(char **strs, int *i)
{
	int	j;

	j = *i;
	while (j > 0)
		free (strs[--j]);
	free(strs);
	return (NULL);
}

static int	str_count(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			i++;
			count++;
		}
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static int	word_len(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static char	*create_word(const char *s, char c)
{
	char	*str;
	int		i;

	i = 0;
	(void)s;
	str = (char *)malloc((sizeof (char)) * (word_len(s, c) + 1));
	if (!str)
		return (NULL);
	while (*s && *s != c)
	{
		str[i] = *s;
		i++;
		s++;
	}
	str[i] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		num_tab;
	char	**strs;
	char	*tmp;

	i = 0;
	num_tab = str_count(s, c);
	strs = (char **)malloc(sizeof (char *) * (num_tab + 1));
	if (!strs)
		return (NULL);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			tmp = create_word(s, c);
			if (!tmp)
				return (ft_free(strs, &i));
			strs[i++] = tmp;
			s += ft_strlen(tmp);
		}
	}
	strs[i] = NULL;
	return (strs);
}

// int main(int ac, char **av)
// {
//     int     i;
//     char    **strs;
//     strs = ft_split(av[1], av[2][0]);
//     if (!strs)
//         return (1);
//     i = 0;
//     (void)ac;
//     while (strs[i] != NULL)
//     {
//         printf("%s\n", strs[i]);
//         i++;
//     }
//     free (strs);
//     return (0);
// }
