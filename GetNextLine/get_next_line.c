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

static char	*extract_line(char **storage)
{
	char	*newline;
	char	*line;
	char	*rest;

	newline = ft_strchr(*storage, '\n');
	if (!newline)
	{
		line = ft_strdup(*storage);
		free(*storage);
		*storage = NULL;
		return (line);
	}
	line = ft_strndup(*storage, (newline - *storage + 1));
	rest = ft_strdup(newline + 1);
	free(*storage);
	*storage = rest;
	if (!*storage)
		*storage = NULL;
	if (!**storage)
	{
		free(*storage);
		*storage = NULL;
	}
	return (line);
}

static char	*parse_storage(int *fd, char **storage, char **buffer)
{
	ssize_t	bytes_read;
	char	*temp;

	while (!ft_strchr(*storage, '\n'))
	{
		bytes_read = read(*fd, *buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(*storage), NULL);
		if (bytes_read == 0)
			break ;
		(*buffer)[bytes_read] = '\0';
		temp = ft_strjoin(*storage, *buffer);
		if (!temp)
			return (free(*storage), NULL);
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
	storage = parse_storage(&fd, &storage, &buffer);
	free(buffer);
	if (!storage)
		return (NULL);
	if (!*storage)
		return (free(storage), NULL);
	return (extract_line(&storage));
}
