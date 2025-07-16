#include "so_long.h"

void	load_images(t_game *game)
{
	int	w;
	int	h;

	game->img.wall = mlx_xpm_file_to_image(game->mlx, "a/w.xpm", &w, &h);
	if (!game->img.wall)
		error_exit("Failed to load wall.xpm");
	game->img.floor = mlx_xpm_file_to_image(game->mlx, "a/f.xpm", &w, &h);
	if (!game->img.floor)
		error_exit("Failed to load floor.xpm");
	game->img.player = mlx_xpm_file_to_image(game->mlx, "a/p.xpm", &w, &h);
	if (!game->img.player)
		error_exit("Failed to load player.xpm");
	game->img.collectible = mlx_xpm_file_to_image(game->mlx, "a/c.xpm", &w, &h);
	if (!game->img.collectible)
		error_exit("Failed to load collectible.xpm");
	game->img.exit = mlx_xpm_file_to_image(game->mlx, "a/e.xpm", &w, &h);
	if (!game->img.exit)
		error_exit("Failed to load exit.xpm");
}

void	x_axis(t_game *game, int *y)
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

void	render_map(t_game *game)
{
	int		y;

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
