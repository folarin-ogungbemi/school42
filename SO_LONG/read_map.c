#include "so_long.h"
#include "GetNextLine/get_next_line.h"

static char	**gnl(int fd, int height, char **map)
{
	int		i;
	char	*line;

	i = 0;
	line = get_next_line(fd);
	while (line && i < height)
	{
		if (!line)
			error_exit("Map has fewer lines", NULL);
		line[ft_strcspn(line, "\n")] = '\0';
		map[i] = ft_strdup(line);
		if (!map[i])
		{
			free(line);
			free_map(map, i);
			error_exit("duplication failed!", NULL);
		}
		free(line);
		i++;
		line = get_next_line(fd);
	}
	map[i] = NULL;
	return (map);
}

char	**load_map(const char *filename, int *height)
{
	int		fd;
	char	**map;

	*height = get_map_height(filename);
	map = (char **)malloc(sizeof(char *) * (*height + 1));
	if (!map)
		error_exit("Malloc failed!", NULL);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		error_exit("Failed to open map file", NULL);
	map = gnl(fd, *height, map);
	if (close(fd) == -1)
		error_exit("Failed closing file", NULL);
	return (map);
}

t_map	*read_map(const char *filename)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		error_exit("Malloc failed to create map!", NULL);
	map->grid = load_map(filename, &map->h);
	if (!map->grid || map->h == 0 || !map->grid[0])
	{
		free_map_struct(map);
		error_exit("Map is not defined!", NULL);
	}
	map->w = ft_strlen(map->grid[0]);
	map->p_count = 0;
	map->e_count = 0;
	map->c_count = 0;
	check_map(map);
	return (map);
}
