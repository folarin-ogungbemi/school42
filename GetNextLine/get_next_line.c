/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foogungb <foogungb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:29:07 by foogungb          #+#    #+#             */
/*   Updated: 2024/12/02 14:20:27 by foogungb         ###   ########.fr       */
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

static char	*extract_line(char **storage)
{
	char	*newline;
	char	*line;
	char	*rest;
	size_t	line_len;

	newline = ft_strchr(*storage, '\n');
	if (!newline)
	{
		line = ft_strdup(*storage);
		free(*storage);
		*storage = NULL;
		return (line);
	}
	line_len = newline - *storage + 1;
	line = ft_strndup(*storage, line_len);
	rest = ft_strdup(newline + 1);
	free(*storage);
	*storage = rest;
	if (!*storage || !**storage)
	{
		free(*storage);
		*storage = NULL;
	}
	return (line);
}

static char	*line(int *fd, char **buffer, char **storage)
{
	char	*temp;
	ssize_t	bytes_read;
	int	counter;

	counter = 0;
	while (!ft_strchr(*storage, '\n'))
	{
		bytes_read = read(*fd, *buffer, BUFFER_SIZE);
		printf("[s:%2d] (%s)\n\n", counter++, *storage);
		printf("[b:%2d] (%s)\n\n", counter, *buffer);
		if (bytes_read < 0)
		{
			free(*storage);
			*storage = NULL;
			return (NULL);
		}
		if (bytes_read == 0)
			break ;
		(*buffer)[bytes_read] = '\0';
		temp = ft_strjoin(*storage, *buffer);
		if (!temp)
		{
			free(*storage);
			*storage = NULL;
			return (NULL);
		}
		free(*storage);
		*storage = temp;
	}
	return (*storage);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*storage;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	storage = line(&fd, &buffer, &storage);
	printf("\n--s(%s)--\n", storage);
	printf("\n--b(%s)--\n", buffer);
	free(buffer);
	if (!storage || !*storage)
	{
		free(storage);
		storage = NULL;
		return (NULL);
	}
	return (extract_line(&storage));
}
