/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foogungb <foogungb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 08:55:19 by foogungb          #+#    #+#             */
/*   Updated: 2024/12/02 12:48:28 by foogungb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_substr(char const *str, char c)
{
	size_t	count;
	int		in_substr;

	count = 0;
	in_substr = 0;
	while (*str)
	{
		if (*str != c && in_substr == 0)
		{
			in_substr = 1;
			count++;
		}
		else if (*str == c)
			in_substr = 0;
		str++;
	}
	return (count);
}

static void	ft_free(char **m, size_t i)
{
	while (i > 0)
		free(m[--i]);
	free (m);
}

static size_t	ft_word_len(const char *s, char c)
{
	const char	*start;

	start = s;
	while (*s && *s != c)
		s++;
	return (s - start);
}

char	**ft_split(char const *s, char c)
{
	size_t		i;
	char		**m;

	i = 0;
	m = (char **)malloc((count_substr(s, c) + 1) * sizeof(char *));
	if (!m)
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			m[i] = ft_substr(s, 0, ft_word_len(s, c));
			if (!m[i++])
			{
				ft_free(m, i);
				return (NULL);
			}
			s += ft_word_len(s, c);
		}
		else
			s++;
	}
	m[i] = NULL;
	return (m);
}
