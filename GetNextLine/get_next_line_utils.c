/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foogungb <foogungb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:46:05 by foogungb          #+#    #+#             */
/*   Updated: 2025/01/16 14:46:29 by foogungb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	ft_strlen(const char *str)
{
	const char	*end;

	end = str;
	while (*end)
		end++;
	return (end - str);
}

char	*ft_strdup(const char *s)
{
	char	*m;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(s);
	if (!s)
		return (NULL);
	m = (char *)malloc((len + 1) * sizeof(char));
	if (!m)
		return (NULL);
	while (s[i])
	{
		m[i] = s[i];
		i++;
	}
	m[i] = '\0';
	return (m);
}

char	*ft_strndup(const char *s, size_t n)
{
	char	*m;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	m = (char *)malloc(sizeof(char) * (n + 1));
	if (!m)
		return (NULL);
	while (s[i] && (i < n))
	{
		m[i] = s[i];
		i++;
	}
	m[i] = '\0';
	return (m);
}

static void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	unsigned int		i;

	d = dest;
	s = src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*m;
	size_t	total_len;
	size_t	len_s1;
	size_t	len_s2;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	total_len = len_s1 + len_s2 + 1;
	m = malloc(sizeof(char) * (total_len));
	if (!m)
		return (NULL);
	ft_memcpy(m, s1, len_s1);
	ft_memcpy(m + len_s1, s2, len_s2);
	m[len_s1 + len_s2] = '\0';
	return (m);
}
