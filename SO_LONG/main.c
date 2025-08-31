#include "so_long.h"
#include "mlx.h"
#include "GetNextLine/get_next_line.h"

void	init_game(t_game *game)
{
	game->mlx = NULL;
	game->win = NULL;
	game->map = NULL;
	game->frame.img = NULL;
	game->frame.addr = NULL;
	game->frame.bpp = 0;
	game->frame.line_len = 0;
	game->frame.endian = 0;
	game->frame.width = 0;
	game->frame.height = 0;
	game->img.wall.img = NULL;
	game->img.wall.addr = NULL;
	game->img.floor.img = NULL;
	game->img.floor.addr = NULL;
	game->img.collectible.img = NULL;
	game->img.collectible.addr = NULL;
	game->img.exit.img = NULL;
	game->img.exit.addr = NULL;
	game->img.player.img = NULL;
	game->img.player.addr = NULL;
	game->player_x = 0;
	game->player_y = 0;
	game->move_count = 0;
}

int	ext_is_valid(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (ft_strcmp(filename + len - 4, ".ber") == 0)
		return (1);
	return (0);
}

void	render_window(t_game *game)
{
	int	win_w;
	int	win_h;

	win_w = game->map->w * TILE_SIZE;
	win_h = game->map->h * TILE_SIZE;
	game->win = mlx_new_window(game->mlx, win_w, win_h, "Coin Collection");
	if (!game->win)
		error_exit("Failed to initialize win", game, NULL);
	load_textures(game);
	game->frame.img = mlx_new_image(game->mlx, win_w, win_h);
	if (!game->frame.img)
		error_exit("Failed to create Frame buffer", game, NULL);
	game->frame.addr = mlx_get_data_addr(
			game->frame.img, &game->frame.bpp,
			&game->frame.line_len, &game->frame.endian);
	game->frame.width = win_w;
	game->frame.height = win_h;
	render_tile(game);
	mlx_put_image_to_window(game->mlx, game->win, game->frame.img, 0, 0);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		error_exit("Usage: ./so_long maps/map.ber", NULL, NULL);
	init_game(&game);
	if (!ext_is_valid(av[1]))
		error_exit("File extension is not valid", NULL, NULL);
	game.map = read_map(av[1], &game);
	if (!game.map)
		error_exit("Failed to read map", NULL, NULL);
	game.mlx = mlx_init();
	if (!game.mlx)
		error_exit("Failed to initialize MLX", NULL, NULL);
	render_window(&game);
	game.move_count = 0;
	mlx_key_hook(game.win, handle_keypress, &game);
	mlx_hook(game.win, 17, (1L << 17), cleanup_wrapper, &game);
	mlx_loop(game.mlx);
	return (0);
}
