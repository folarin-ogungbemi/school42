#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef TILE_SIZE
#  define TILE_SIZE 64
# endif

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define ESC_KEY 65307

# include <unistd.h>
# include <stdio.h>
# include <errno.h>
# include <stdlib.h>
# include <fcntl.h>
# include "mlx.h"

typedef struct s_map
{
	char	**grid;
	int		w;
	int		h;
	int		p_count;
	int		e_count;
	int		c_count;
}	t_map;

typedef struct s_img
{
	void	*wall;
	void	*floor;
	void	*player;
	void	*collectible;
	void	*exit;
}	t_img;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_map	*map;
	t_img	img;
	int		move_count;
	int		player_x;
	int		player_y;
}	t_game;

t_map	*read_map(const char *filename);
void	validate_map(t_map *map, t_game *game);
char	**load_map(const char *file, int *height);
void	load_textures(t_game *game);
void	render_tile(t_game *game);
int		get_map_height(const char *filename);
int		handle_keypress(int keycode, t_game *game);
int		get_map_height(const char *filename);
void	error_exit(const char *msg, t_game *game);
void	free_map(char **map, int lines);
void	free_map_struct(t_map *map);
size_t	ft_strcspn(const char *s, const char *reject);
int	find_player_position(t_map *map, int *player_x, int *player_y);
void	validate_map_solvability(t_map *map, int player_x, int player_y);
void	check_map(t_map *map);
void    cleanup(t_game *game);
int	cleanup_wrapper(void *param);
#endif
