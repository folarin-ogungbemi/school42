#include "so_long.h"

int	handle_exit(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(EXIT_SUCCESS);
	return (0);
}

int	can_move_to(t_game *game, int x, int y)
{
	if (x < 0
		|| y < 0
		|| x >= game->map->w
		|| y >= game->map->h)
		return (0);
	if (game->map->grid[y][x] == '1')
		return (0);
	return (1);
}

void	move_player(t_game *game, int x, int y)
{
	game->player_x = x;
	game->player_y = y;
	if (game->map->grid[y][x] == 'C')
	{
		game->map->grid[y][x] = '0';
		game->map->c_count--;
	}
	if (game->map->grid[y][x] == 'E' && game->map->c_count == 0)
		handle_exit(game);
}

int	handle_keypress(int keycode, t_game *game)
{
	int	x;
	int	y;

	x = game->player_x;
	y = game->player_y;
	if (keycode == KEY_W)
		y--;
	else if (keycode == KEY_S)
		y++;
	else if (keycode == KEY_A)
		x--;
	else if (keycode == KEY_D)
		x++;
	else if (keycode == ESC_KEY)
		handle_exit(game);
	if (can_move_to(game, x, y))
	{
		move_player(game, x, y);
		render_map(game);
	}
	return (0);
}
