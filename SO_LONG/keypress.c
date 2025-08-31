/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foogungb <foogungb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 16:39:00 by foogungb          #+#    #+#             */
/*   Updated: 2025/08/04 17:52:46 by foogungb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

static void	ft_putnbr(int n)
{
	char	digit;

	if (n >= 0)
	{
		if (n > 9)
			ft_putnbr(n / 10);
		digit = (n % 10) + 48;
		(void)!write(1, &digit, 1);
	}
}

static int	can_move_to(t_game *game, int y, int x)
{
	if (!game || !game->map || !game->map->grid
		|| !game->map->grid[y])
		return (0);
	if (y < 0 || x < 0 || y >= game->map->h
		|| x >= game->map->w)
		return (0);
	if (game->map->grid[y][x] == '1')
		return (0);
	return (1);
}

static void	move_player(t_game *game, int y, int x)
{
	char	*tile;

	if (!can_move_to(game, y, x))
		return;
	tile = &game->map->grid[y][x];
	if (game->player_y != y || game->player_x != x)
	{
		game->player_y = y;
		game->player_x = x;
		game->move_count++;
		ft_putnbr(game->move_count);
		(void)!write(1, "\n", 1);
	}
	if (*tile == 'C')
	{
		*tile = '0';
		game->map->c_count--;
	}
	if (*tile == 'E' && game->map->c_count == 0)
	{
		cleanup(game);
		exit(EXIT_SUCCESS);
	}
	render_tile(game);
	mlx_put_image_to_window(game->mlx, game->win, game->frame.img, 0, 0);
}

int	handle_keypress(t_keys key, t_game *game)
{
	int	y;
	int	x;

	y = game->player_y;
	x = game->player_x;
	if (key == KEY_W)
		y--;
	else if (key == KEY_S)
		y++;
	else if (key == KEY_A)
		x--;
	else if (key == KEY_D)
		x++;
	else if (key == ESC_KEY)
	{
		cleanup(game);
		exit(EXIT_SUCCESS);
	}
	if (can_move_to(game, y, x))
		move_player(game, y, x);
	return (0);
}
