#include "so_long.h"

void	load_texture(t_game *game, t_texture *tex, char *path)
{
	tex->img = mlx_xpm_file_to_image(
			game->mlx, path, &tex->width, &tex->height);
	if (!tex->img)
		error_exit("Failed to load texture", game, NULL);
	tex->addr = mlx_get_data_addr(
			tex->img, &tex->bpp, &tex->line_len, &tex->endian);
	if (!tex->addr)
		error_exit("Failed to get texture data address", game, NULL);
}

void	load_textures(t_game *game)
{
	load_texture(game, &game->img.wall, "a/w.xpm");
	load_texture(game, &game->img.floor, "a/f.xpm");
	load_texture(game, &game->img.player, "a/p.xpm");
	load_texture(game, &game->img.collectible, "a/c.xpm");
	load_texture(game, &game->img.exit, "a/e.xpm");
}
