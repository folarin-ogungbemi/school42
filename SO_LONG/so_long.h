#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <stdlib.h>
# include <fcntl.h>
# include "mlx.h"

enum
{
	TILE_SIZE = 64
};

typedef enum s_keys
{
	KEY_W = 119,
	KEY_A = 97,
	KEY_S = 115,
	KEY_D = 100,
	ESC_KEY = 65307,
}	t_keys;

typedef struct s_map
{
	char	**grid;
	int		w;
	int		h;
	int		p_count;
	int		e_count;
	int		c_count;
}	t_map;

typedef struct s_texture
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}	t_texture;

typedef struct s_img
{
	t_texture	wall;
	t_texture	floor;
	t_texture	player;
	t_texture	collectible;
	t_texture	exit;
}	t_img;

typedef struct s_frame
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}	t_frame;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_frame	frame;
	t_map	*map;
	t_img	img;
	int		move_count;
	int		player_x;
	int		player_y;
}	t_game;

t_map	*read_map(const char *filename, t_game *game);
void	validate_map(t_game *game);
void	load_textures(t_game *game);
void	render_tile(t_game *game);
int		handle_keypress(t_keys keycode, t_game *game);
int		get_map_height(const char *filename);
void	free_map(char **map, int lines);
void	free_map_struct(t_map *map);
int	ft_strcmp(char *s1, char *s2);
size_t	ft_strcspn(const char *s, const char *reject);
int		has_unreachable_items(char **grid, int width, int height);
char	**duplicate_map(char **grid, int height);
void	flood_fill(char **grid, int x, int y);
int		cleanup_wrapper(void *param);
void	cleanup(t_game *game);
void	error_exit(const char *msg, t_game *game, char **copy);
#endif
