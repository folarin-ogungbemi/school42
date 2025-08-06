#include "so_long.h"

int	main(int ac, char **av)
{
	t_game	game;
	int	win_w;
	int	win_h;

	if (ac != 2)
		error_exit("Usage: ./so_long maps/map.ber", NULL);
	game.map = read_map(av[1]);
	if (!game.map)
		error_exit("Failed to read map", NULL);
	validate_map(game.map, &game);
	game.mlx = mlx_init();
	if (!game.mlx)
		error_exit("Failed to initialize MLX", &game);
	win_w = game.map->w * TILE_SIZE;
	win_h = game.map->h * TILE_SIZE;
	game.win = mlx_new_window(game.mlx, win_w, win_h, "Coin Collection");
	if (!game.win)
		error_exit("Failed to initialized win", &game);
	load_textures(&game);
	game.move_count = 0;
	render_tile(&game);
	mlx_key_hook(game.win, handle_keypress, &game);
	mlx_hook(game.win, 17, (1L << 17), cleanup_wrapper, &game);
	mlx_loop(game.mlx);
	return (0);
}
