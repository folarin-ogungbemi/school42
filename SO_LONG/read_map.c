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
			error_exit("Error: Map has fewer lines", NULL, NULL);
		line[ft_strcspn(line, "\n")] = '\0';
		map[i] = ft_strdup(line);
		if (!map[i])
		{
			free(line);
			free_map(map, i);
			error_exit("Error: duplication failed!", NULL, NULL);
		}
		free(line);
		i++;
		line = get_next_line(fd);
	}
	map[i] = NULL;
	return (map);
}

static char	**load_map(const char *filename, t_game *game)
{
	int		fd;
	int		height;
	char	**map;

	height = get_map_height(filename);
	game->map->h = height;
	map = (char **)malloc(sizeof(char *) * (height + 1));
	if (!map)
		error_exit("Error: Malloc failed!", game, NULL);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		error_exit("Error: Failed to open map file", game, map);
	map = gnl(fd, height, map);
	if (!map)
		error_exit("Error in gnl", game, map);
	if (close(fd) == -1)
		error_exit("Error: Failed closing file", game, map);
	return (map);
}

t_map	*read_map(const char *filename, t_game *game)
{
	game->map = malloc(sizeof(t_map));
	if (!game->map)
		error_exit("Error: Malloc failed to create map!", game, NULL);
	game->map->grid = NULL;
	game->map->grid = load_map(filename, game);
	if (!game->map->grid || game->map->h == 0 || !game->map->grid[0])
		error_exit("Error: Map is not defined!", game, NULL);
	game->map->w = ft_strlen(game->map->grid[0]);
	game->map->p_count = 0;
	game->map->e_count = 0;
	game->map->c_count = 0;
	validate_map(game);
	return (game->map);
}
