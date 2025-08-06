#include "so_long.h"

void	load_textures(t_game *game)
{
	int	w;
	int	h;

	game->img.wall = mlx_xpm_file_to_image(game->mlx, "a/w.xpm", &w, &h);
	if (!game->img.wall)
		error_exit("Failed to load wall.xpm", game);
	game->img.floor = mlx_xpm_file_to_image(game->mlx, "a/f.xpm", &w, &h);
	if (!game->img.floor)
		error_exit("Failed to load floor.xpm", game);
	game->img.player = mlx_xpm_file_to_image(game->mlx, "a/p.xpm", &w, &h);
	if (!game->img.player)
		error_exit("Failed to load player.xpm", game);
	game->img.collectible = mlx_xpm_file_to_image(game->mlx, "a/c.xpm", &w, &h);
	if (!game->img.collectible)
		error_exit("Failed to load collectible.xpm", game);
	game->img.exit = mlx_xpm_file_to_image(game->mlx, "a/e.xpm", &w, &h);
	if (!game->img.exit)
		error_exit("Failed to load exit.xpm", game);
}
