/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foogungb <foogungb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:44:45 by foogungb          #+#    #+#             */
/*   Updated: 2025/01/20 16:22:21 by foogungb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	i = 0;
	d = dest;
	s = src;
	if (s > d)
	{
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	else if (s < d)
	{
		i = n;
		while (i > 0)
		{
			d[i - 1] = s[i - 1];
			i--;
		}
	}
	return (dest);
}

static char	*extract_line(t_gnl_state *s)
{
	char	*newline;
	char	*line;

	if (!s->data)
		return (NULL);
	newline = ft_strchr(s->data, '\n');
	if (!newline)
	{
		line = ft_strdup(s->data);
		free(s->data);
		s->data = NULL;
		return (line);
	}
	line = ft_strndup(s->data, (newline - s->data + 1));
	ft_memmove(s->data, newline + 1, ft_strlen(newline + 1) + 1);
	s->data[ft_strlen(newline + 1) + 1] = '\0';
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
			if (s->data)
			{
				free(s->data);
				s->data = NULL;
			}
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
	if (!s.data || !*s.data)
		return (free(s.data), NULL);
	return (extract_line(&s));
}
