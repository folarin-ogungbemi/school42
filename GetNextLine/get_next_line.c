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

static char	*free_m(char **buffer, char **storage)
{
	free(*storage);
	free(buffer);
	*storage = NULL;
	return (NULL);
}

char	*get_next_line(int fd)
{
	ssize_t		bytes_read;
	char		*buffer;
	char		*temp;
	static char	*storage;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while (!ft_strchr(storage, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			free_m(&buffer, &storage);
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		temp = ft_strjoin(storage, buffer);
		if (!temp)
			free_m(&buffer, &storage);
		free(storage);
		storage = temp;
	}
	free(buffer);
	if (!storage || !*storage)
	{
		free(storage);
		storage = NULL;
		return (NULL);
	}
	return (extract_line(&storage));
}

int	main(void)
{
	int		fd;
	char	*str;

	fd = open("ex.txt", O_RDONLY);
	if (fd < 0)
		return (1);
	while ((str = get_next_line(fd)) != NULL)
	{
		printf("sleep ...\n");
		sleep(2);
		printf("%s", str);
		printf("wake ..\n");
		free(str);
	}
	close(fd);
	return (0);
}
