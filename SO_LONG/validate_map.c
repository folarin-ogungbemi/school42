#include "so_long.h"
#include "GetNextLine/get_next_line.h"

static void	col_axis(t_game *game, char **v_map, int *y)
{
	char	c;
	int		x;

	x = 0;
	while (x < game->map->w)
	{
		c = game->map->grid[*y][x];
		if (c != '0' && c != '1' && c != 'P' && c != 'E' && c != 'C')
			error_exit("Error: Invalid character in map", game, v_map);
		if ((*y == 0 || *y == game->map->h - 1 || x == 0
				|| x == game->map->w - 1) && c != '1')
			error_exit("Error: Map must be surrounded by walls", game, v_map);
		if (c == 'P')
		{
			game->map->p_count++;
			game->player_x = x;
			game->player_y = *y;
			v_map[*y][x] = '0';
		}
		else if (c == 'E')
			game->map->e_count++;
		else if (c == 'C')
			game->map->c_count++;
		x++;
	}
}

static void	check_map(t_game *game, char **copy)
{
	if (game->map->p_count != 1)
		error_exit("Error: Map must have exactly one player", game, copy);
	if (game->map->e_count != 1)
		error_exit("Error: Map must have exactly one exit", game, copy);
	if (game->map->c_count < 1)
		error_exit("Error: Map must have at least one collectible", game, copy);
	flood_fill(copy, game->player_y, game->player_x);
	if (has_unreachable_items(copy, game->map->w, game->map->h))
		error_exit("Error: Map is unsolvable", game, copy);
	free_map(copy, game->map->h);
}

void	validate_map(t_game *game)
{
	char	**copy;
	int		y;

	if (!game->map || !game->map->grid || game->map->w <= 0
		|| game->map->h <= 0)
		error_exit("Error: Invalid map", game, NULL);
	copy = duplicate_map(game->map->grid, game->map->h);
	if (!copy)
		error_exit("Memory error during map copy", game, copy);
	y = 0;
	while (y < game->map->h)
	{
		if (!game->map->grid[y])
			error_exit("Error: Invalid map y", game, copy);
		if ((int)ft_strlen(game->map->grid[y]) != game->map->w)
			error_exit("Error: Map is not rectangular", game, copy);
		col_axis(game, copy, &y);
		y++;
	}
	check_map(game, copy);
}
