#include "so_long.h"
#include "GetNextLine/get_next_line.h"

static void	destroy_img(t_game *game)
{
	if (game->img.wall.img)
		mlx_destroy_image(game->mlx, game->img.wall.img);
	if (game->img.floor.img)
		mlx_destroy_image(game->mlx, game->img.floor.img);
	if (game->img.player.img)
		mlx_destroy_image(game->mlx, game->img.player.img);
	if (game->img.collectible.img)
		mlx_destroy_image(game->mlx, game->img.collectible.img);
	if (game->img.exit.img)
		mlx_destroy_image(game->mlx, game->img.exit.img);
	if (game->frame.img)
		mlx_destroy_image(game->mlx, game->frame.img);
}

void	cleanup(t_game *game)
{
	int	i;

	if (!game)
		return ;
	if (game->map)
	{
		if (game->map->grid)
		{
			i = 0;
			while (game->map->grid[i])
				free(game->map->grid[i++]);
			free(game->map->grid);
		}
		free(game->map);
		game->map = NULL;
	}
	if (game->mlx)
		destroy_img(game);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
}

int	cleanup_wrapper(void *param)
{
	cleanup((t_game *)param);
	exit(0);
	return (0);
}

void	error_exit(const char *msg, t_game *game, char **copy)
{
	int	i;

	i = 0;
	if (copy)
	{
		while (i < game->map->h)
			free(copy[i++]);
		free(copy);
	}
	cleanup(game);
	if (errno != 0)
	{
		(void)!write(2, msg, ft_strlen(msg));
		(void)!write(2, ": ", 2);
		(void)!write(2, strerror(errno), ft_strlen(strerror(errno)));
		(void)!write(2, "\n", 1);
	}
	else
	{
		(void)!write(2, msg, ft_strlen(msg));
		(void)!write(2, "\n", 1);
	}
	exit(EXIT_FAILURE);
}
