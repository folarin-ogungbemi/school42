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

#include "get_next_line_bonus.h"

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

static char	*extract_line(t_gnl_state *s, int fd)
{
	char	*newline;
	char	*line;

	newline = ft_strchr(s->data[fd], '\n');
	if (!newline)
	{
		line = ft_strdup(s->data[fd]);
		free(s->data[fd]);
		s->data[fd] = NULL;
		return (line);
	}
	line = ft_strndup(s->data[fd], (newline - s->data[fd] + 1));
	ft_memmove(s->data[fd], newline + 1, ft_strlen(newline + 1) + 1);
	if (!*s->data[fd])
	{
		free(s->data[fd]);
		s->data[fd] = NULL;
	}
	return (line);
}

static void	parse_data(int fd, t_gnl_state *s)
{
	char	*temp;

	while (!ft_strchr(s->data[fd], '\n'))
	{
		s->bread = read(fd, s->buf, BUFFER_SIZE);
		if (s->bread < 0)
		{
			free(s->data[fd]);
			s->data[fd] = NULL;
			break ;
		}
		if (s->bread == 0)
			break ;
		s->buf[s->bread] = '\0';
		temp = ft_strjoin(s->data[fd], s->buf);
		if (!temp)
		{
			free(s->data[fd]);
			s->data[fd] = NULL;
			break ;
		}
		free(s->data[fd]);
		s->data[fd] = temp;
	}
}

char	*get_next_line(int fd)
{
	static t_gnl_state	s;

	s.buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE <= 0 || !s.buf)
		return (free(s.buf), NULL);
	parse_data(fd, &s);
	free(s.buf);
	if (!s.data[fd])
		return (NULL);
	if (!*s.data[fd])
		return (free(s.data[fd]), NULL);
	return (extract_line(&s, fd));
}
