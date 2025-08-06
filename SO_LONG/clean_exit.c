#include "so_long.h"
#include "GetNextLine/get_next_line.h"

void	destroy_img(t_game *game)
{
	if (game->img.wall)
		mlx_destroy_image(game->mlx, game->img.wall);
	if (game->img.floor)
		mlx_destroy_image(game->mlx, game->img.floor);
	if (game->img.player)
		mlx_destroy_image(game->mlx, game->img.player);
	if (game->img.collectible)
		mlx_destroy_image(game->mlx, game->img.collectible);
	if (game->img.exit)
		mlx_destroy_image(game->mlx, game->img.exit);
}

void    cleanup(t_game *game)
{
	int	i;

	i = 0;
	if (game->map)
	{
		if (game->map->grid)
		{
			while (game->map->grid[i])
                		free(game->map->grid[i++]);
			free(game->map->grid);
		}
		free(game->map);
	}
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	destroy_img(game);
	if (game->mlx)
		mlx_destroy_display(game->mlx);
}

int	cleanup_wrapper(void *param)
{
	cleanup((t_game *)param);
	exit(0);
	return (0);
}

void	error_exit(const char *msg, t_game *game)
{
	cleanup(game);
	if (errno != 0)
		perror(msg);
	else
	{
		(void)!write(2, msg, ft_strlen(msg));
		(void)!write(2, "\n", 1);
	}
	exit(EXIT_FAILURE);
}
