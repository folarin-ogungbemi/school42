#include "so_long.h"
#include "GetNextLine/get_next_line.h"

static void	x_axis(t_map *map, int *y, t_game *game)
{
	char	c;
	int		x;

	x = 0;
	while (x < map->w)
	{
		c = map->grid[*y][x];
		if (c != '0' && c != '1' && c != 'P' && c != 'E' && c != 'C')
			error_exit("Invalid character in map", game);
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
			error_exit("Map must be surrounded by walls", game);
		x++;
	}
}

void	validate_map(t_map *map, t_game *game)
{
	int	y;

	if (!map || !map->grid || map->w <= 0 || map->h <= 0)
		error_exit("Invalid map", game);
	y = 0;
	while (y < map->h)
	{
		if (!map->grid[y])
			error_exit("Invalid map row", game);
		if ((int)ft_strlen(map->grid[y]) != map->w)
			error_exit("Map is not rectangular", game);
		x_axis(map, &y, game);
		y++;
	}
	if (map->p_count != 1)
		error_exit("Map must have exactly one player", game);
	if (map->e_count < 1)
		error_exit("Map must have at least one exit", game);
	if (map->c_count < 1)
		error_exit("Map must have at least one collectible", game);
}
