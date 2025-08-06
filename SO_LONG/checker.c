#include "so_long.h"
#include "GetNextLine/get_next_line.h"

int	find_player_position(t_map *map, int *player_x, int *player_y)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->h)
	{
		x = 0;
		while (x < map->w)
		{
			if (map->grid[y][x] == 'P')
			{
				*player_x = x;
				*player_y = y;
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

char	**duplicate_map(char **grid, int height)
{
	char	**copy;
	int		i;
	int		j;

	i = 0;
	copy = (char **)malloc((height + 1) * (sizeof(char *)));
	if (!copy)
		return (NULL);
	while (i < height)
	{
		copy[i] = ft_strdup(grid[i]);
		if (!copy[i])
		{
			j = 0;
			while (j < i)
				free(copy[j++]);
			free(copy);
			return (NULL);
		}
		i++;
	}
	copy[height] = NULL;
	return (copy);
}

void	flood_fill(char **grid, int x, int y)
{
	int	y_len;

	y_len = ft_strlen(grid[y]);
	if (y < 0 || x < 0 || !grid[y] || x >= y_len)
		return ;
	if (grid[y][x] == '1' || grid[y][x] == 'V')
		return ;
	grid[y][x] = 'V';
	flood_fill(grid, x + 1, y);
	flood_fill(grid, x - 1, y);
	flood_fill(grid, x, y + 1);
	flood_fill(grid, x, y - 1);
}

int	has_unreachable_items(char **grid, int width, int height)
{
	int	x;
	int	y;

	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			if (grid[y][x] == 'C' || grid[y][x] == 'E')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

void	validate_map_solvability(t_map *map, int player_x, int player_y)
{
	char	**copy;
	int		i;

	copy = duplicate_map(map->grid, map->h);
	if (!copy)
		error_exit("Memory error during map copy", NULL);
	flood_fill(copy, player_x, player_y);
	if (has_unreachable_items(copy, map->w, map->h))
	{
		i = 0;
		while (i < map->h)
			free(copy[i++]);
		free(copy);
		error_exit("Error: Map is unsolvable", NULL);
	}
	i = 0;
	while (i < map->h)
		free(copy[i++]);
	free(copy);
}
