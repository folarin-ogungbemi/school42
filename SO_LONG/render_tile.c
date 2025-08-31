#include "so_long.h"

void	put_tile_to_frame(t_game *game, t_texture *tex, int dst_x, int dst_y)
{
	unsigned int	pixel;
	int				x;
	int				y;
	char			*src;
	char			*dst;

	y = 0;
	while (y < tex->height)
	{
		x = 0;
		while (x < tex->width)
		{
			src = tex->addr + (
					y * tex->line_len + x * (tex->bpp / 8));
			pixel = *(unsigned int *)src;
			dst = game->frame.addr + (
					(dst_y + y) * game->frame.line_len + (
						dst_x + x) * (game->frame.bpp / 8));
			*(unsigned int *)dst = pixel;
			x++;
		}
		y++;
	}
}

void	render_tile_x(t_game *game, int *y)
{
	int		x;
	char	c;

	x = 0;
	while (x < game->map->w)
	{
		c = game->map->grid[*y][x];
		put_tile_to_frame(
			game, &game->img.floor, x * TILE_SIZE, *y * TILE_SIZE);
		if (c == '1')
			put_tile_to_frame(
				game, &game->img.wall, x * TILE_SIZE, *y * TILE_SIZE);
		else if (c == 'C')
			put_tile_to_frame(
				game, &game->img.collectible, x * TILE_SIZE, *y * TILE_SIZE);
		else if (c == 'E')
			put_tile_to_frame(
				game, &game->img.exit, x * TILE_SIZE, *y * TILE_SIZE);
		x++;
	}
}

void	render_tile(t_game *game)
{
	int		y;

	y = 0;
	while (y < game->map->h)
	{
		render_tile_x(game, &y);
		y++;
	}
	put_tile_to_frame(
		game, &game->img.player,
		game->player_x * TILE_SIZE,
		game->player_y * TILE_SIZE);
}
