#include "so_long.h"

int	main(int ac, char **av)
{
	t_game	game;
	t_map	map;

	if (ac != 2)
		error_exit("Usage: ./so_long maps/map.ber");
	game.map = read_map(av[1]);
	validate_map(game.map, &game);
	game.mlx = mlx_init();
	map.w = game.map->w * TILE_SIZE;
	map.h = game.map->h * TILE_SIZE;
	if (!game.mlx)
		error_exit("Failed to initialized MLX");
	game.win = mlx_new_window(game.mlx, map.w, map.h, "Coin Collection");
	load_images(&game);
	render_map(&game);
	mlx_key_hook(game.win, handle_keypress, &game);
	mlx_hook(game.win, 17, 0L, handle_exit, &game);
	mlx_loop(game.mlx);
	free_map(game.map);
	return (0);
}
