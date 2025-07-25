#include "so_long.h"

size_t	ft_strcspn(const char *s, const char *reject)
{
	const char	*str;
	const char	*r;

	str = s;
	while (*s)
	{
		r = reject;
		while (*r)
		{
			if (*s == *r)
				return (s - str);
			r++;
		}
		s++;
	}
	return (s - str);
}

int	get_map_height(const char *filename)
{
	int		fd;
	int		last_nline;
	int		height;
	char	c;

	last_nline = 0;
	height = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	while (read(fd, &c, 1) > 0)
	{
		if (c == '\n')
		{
			height++;
			last_nline = 1;
		}
		else
			last_nline = 0;
	}
	if (!last_nline)
		height++;
	if (close(fd) == -1)
		error_exit("Could not close file");
	return (height);
}

void	error_exit(const char *msg)
{
	ssize_t	ignored;

	if (errno != 0)
		perror(msg);
	else
	{
		ignored = write(2, msg, strlen(msg));
		(void)ignored;
		ignored = write(2, "\n", 1);
		(void)ignored;
	}
	exit(EXIT_FAILURE);
}

void	free_map(t_map *map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map->grid[i])
		free(map->grid[i++]);
	free(map->grid);
	free(map);
}
