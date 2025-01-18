/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foogungb <foogungb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:44:45 by foogungb          #+#    #+#             */
/*   Updated: 2025/01/17 20:08:54 by foogungb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

static char	*ft_strndup(const char *s, size_t n)
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

static char	*extract_line(t_gnl_state *s)
{
	s->nline = ft_strchr(s->data, '\n');
	if (!s->nline)
	{
		s->line = ft_strdup(s->data);
		free(s->data);
		s->data = NULL;
		return (s->line);
	}
	s->line = ft_strndup(s->data, (s->nline - s->data + 1));
	s->rest = ft_strdup(s->nline + 1);
	free(s->data);
	s->data = s->rest;
	if (!s->data)
		s->data = NULL;
	if (!*s->data)
	{
		free(s->data);
		s->data = NULL;
	}
	return (s->line);
}

static char	*parse_data(int *fd, t_gnl_state *s)
{
	while (!ft_strchr(s->data, '\n'))
	{
		s->bread = read(*fd, s->buf, BUFFER_SIZE);
		if (s->bread < 0)
			return (free(s->data), NULL);
		if (s->bread == 0)
			break ;
		(s->buf)[s->bread] = '\0';
		s->temp = ft_strjoin(s->data, s->buf);
		if (!s->temp)
			return (free(s->data), NULL);
		free(s->data);
		s->data = s->temp;
		s->temp = NULL;
	}
	return (s->data);
}

char	*get_next_line(int fd)
{
	static t_gnl_state	s;

	s.buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0 || !s.buf)
		return (free(s.buf), NULL);
	s.data = parse_data(&fd, &s);
	free(s.buf);
	if (!s.data)
		return (NULL);
	if (!*s.data)
		return (free(s.data), NULL);
	return (extract_line(&s));
}
