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
			error_exit("Map has fewer lines has expected");
		line[ft_strcspn(line, "\n")] = '\0';
		map[i] = ft_strdup(line);
		if (!map[i])
			error_exit("duplication failed!");
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
		error_exit("Malloc failed!");
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		error_exit("Failed to open map file");
	map = gnl(fd, *height, map);
	if (close(fd) == -1)
		error_exit("Failed closing file");
	return (map);
}

t_map	*read_map(const char *filename)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		error_exit("Malloc failed to create map!");
	map->grid = load_map(filename, &map->h);
	if (!map->grid)
	{
		error_exit("Malloc failed to create map grid!");
		free_map(map);
	}
	if (map->h == 0 || !map->grid[0])
	{
		error_exit("Map is not defined!");
		free_map(map);
	}
	map->w = ft_strlen(map->grid[0]);
	map->p_count = 0;
	map->e_count = 0;
	map->c_count = 0;
	return (map);
}

static void	x_axis(t_map *map, int *y, t_game *game)
{
	char	c;
	int		x;

	x = 0;
	while (x < map->w)
	{
		c = map->grid[*y][x];
		if (c != '0' && c != '1' && c != 'P' && c != 'E' && c != 'C')
			error_exit("Invalid character in map");
		if (c == 'P')
		{
			map->p_count++;
			game->player_x = x;
			game->player_y = *y;
			map->grid[*y][x] = '0';
		}
		else if (c == 'E')
			map->e_count++;
		else if (c == 'C')
			map->c_count++;
		if ((*y == 0 || *y == map->h - 1 || x == 0 || x == map->w - 1)
			&& c != '1')
			error_exit("Map must be surrounded by walls");
		x++;
	}
}

void	validate_map(t_map *map, t_game *game)
{
	int	y;

	y = 0;
	while (y < map->h)
	{
		if (!map->grid[y])
			error_exit("Invalid map row");
		if ((int)strlen(map->grid[y]) != map->w)
			error_exit("Map is not rectangular");
		x_axis(map, &y, game);
		y++;
	}
	if (map->p_count != 1)
		error_exit("Map must have exactly one player");
	if (map->e_count < 1)
		error_exit("Map must have at least one exit");
	if (map->c_count < 1)
		error_exit("Map must have at least one collectible");
}
