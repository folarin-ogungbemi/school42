/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foogungb <foogungb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:21:47 by foogungb          #+#    #+#             */
/*   Updated: 2024/12/05 19:50:13 by foogungb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Function allocates an empty memory if string is null */
static char	*ft_empty_str(char const *s1, size_t len)
{
	if (s1 == NULL || s1[0] == '\0' || len == 0)
		return (NULL);
	return (NULL);
}

/* Function returns the no occurence index of string c
 * from the start of the string s */
static size_t	ft_start(const char *s, char const *c)
{
	size_t	start;

	start = 0;
	while (s[start] && (ft_strchr(c, s[start])))
		start++;
	return (start);
}

/* Function returns the no occurence index of string c
 * from the string s length */
static size_t	ft_end(const char *s, char const *c)
{
	size_t	end;
	size_t	len;

	len = ft_strlen(s);
	end = len - 1;
	while (s[end] && (ft_strchr(c, s[end])))
		end--;
	return (end);
}

/* Function returns a non negative length of the sum
 * of end and start of the str */
static size_t	ft_len(char const *s, char const *c)
{
	int	len;
	int	start;
	int	end;

	end = ft_end(s, c);
	start = ft_start(s, c);
	if (end < start)
		len = 0;
	else
		len = end - start + 1;
	return ((size_t)len);
}

/* Allocates (with malloc(3)) and returns a copy of ’s1’ with
 * the characters specified in ’set’ removed from the beginning
 * and the end of the string.*/
char	*ft_strtrim(char const *s1, char const *set)
{
	char	*m;
	size_t	len;
	size_t	i;
	size_t	start;

	i = 0;
	len = ft_len(s1, set);
	m = ft_empty_str(s1, len);
	if (m)
		return (m);
	m = (char *)malloc(sizeof(char) * (len + 1));
	if (!m)
		return (NULL);
	start = ft_start(s1, set);
	while (i < len)
	{
		m[i] = s1[start + i];
		i++;
	}
	m[i] = '\0';
	return (m);
}
