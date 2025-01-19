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

static char	*extract_line(t_gnl_state *s)
{
	char	*newline;
	char	*line;
	char	*rest;

	newline = ft_strchr(s->data, '\n');
	if (!newline)
	{
		line = ft_strdup(s->data);
		free(s->data);
		s->data = NULL;
		return (line);
	}
	line = ft_strndup(s->data, (newline - s->data + 1));
	rest = ft_strdup(newline + 1);
	free(s->data);
	s->data = rest;
	if (!s->data)
		s->data = NULL;
	if (!*s->data)
	{
		free(s->data);
		s->data = NULL;
	}
	return (line);
}

static void	parse_data(int *fd, t_gnl_state *s)
{
	char	*temp;

	while (!ft_strchr(s->data, '\n'))
	{
		s->bread = read(*fd, s->buf, BUFFER_SIZE);
		if (s->bread < 0)
		{
			free(s->data);
			s->data = NULL;
			break ;
		}
		if (s->bread == 0)
			break ;
		s->buf[s->bread] = '\0';
		temp = ft_strjoin(s->data, s->buf);
		if (!temp)
		{
			free(s->data);
			s->data = NULL;
			break ;
		}
		free(s->data);
		s->data = temp;
	}
}

char	*get_next_line(int fd)
{
	static t_gnl_state	s;

	s.buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0 || !s.buf)
		return (free(s.buf), NULL);
	parse_data(&fd, &s);
	free(s.buf);
	if (!s.data)
		return (NULL);
	if (!*s.data)
		return (free(s.data), NULL);
	return (extract_line(&s));
}
