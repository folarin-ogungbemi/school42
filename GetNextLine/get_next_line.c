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


static char *extract_line(char **storage)
{
	char *newline;
	char *line;
	char *rest;
	size_t	line_len;

	newline = ft_strchr(*storage, '\n');
	if (newline)
	{
		line_len = newline - *storage + 1;
		line = ft_strndup(*storage, line_len);
		rest = ft_strdup(newline + 1);
		free(*storage);
		*storage = rest;
	}
	else
	{
		line = ft_strdup(*storage);
		free(*storage);
		*storage = NULL;
	}
	return line;
}

char	*get_next_line(int fd)
{
	char	*buffer;
	size_t	bytes_read;
	static char	*storage;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	if (!storage)
		storage = ft_strdup("");
	while (!ft_strchr(storage, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break;
		buffer[bytes_read] = '\0';
		storage = ft_strjoin(storage, buffer);
	}
	free(buffer);
	if (!storage || !*storage)
		return (NULL);
	return (extract_line(&storage));
}

int	main(void)
{
	int	fd;
	char	*str;

	fd = open("ex.txt", O_RDONLY);
	if (fd < 0)
		return (1);
	while ((str = get_next_line(fd)) != NULL)
	{
		printf("%s", str);
		free(str);
	}
	close(fd);
	return (0);
}
