#include "so_long.h"

static void	x_axis(t_game *game, int *y)
{
	int		x;
	char	c;

	x = 0;
	while (x < game->map->w)
	{
		c = game->map->grid[*y][x];
		mlx_put_image_to_window(game->mlx, game->win,
			game->img.floor, x * TILE_SIZE, *y * TILE_SIZE);
		if (c == '1')
			mlx_put_image_to_window(game->mlx, game->win,
				game->img.wall, x * TILE_SIZE, *y * TILE_SIZE);
		else if (c == 'C')
			mlx_put_image_to_window(game->mlx, game->win,
				game->img.collectible, x * TILE_SIZE, *y * TILE_SIZE);
		else if (c == 'E')
			mlx_put_image_to_window(game->mlx, game->win,
				game->img.exit, x * TILE_SIZE, *y * TILE_SIZE);
		x++;
	}
}

void	render_tile(t_game *game)
{
	int		y;

	if (!game || !game->mlx || !game->win || !game->map || !game->map->grid
			|| !game->img.wall || !game->img.floor
			|| !game->img.player || !game->img.collectible
			|| !game->img.exit)
		return;
	y = 0;
	while (y < game->map->h)
	{
		x_axis(game, &y);
		y++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img.player,
		game->player_x * TILE_SIZE,
		game->player_y * TILE_SIZE);
}
