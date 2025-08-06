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

static int	can_move_to(t_game *game, int x, int y)
{
	if (!game || !game->map || !game->map->grid
		|| !game->map->grid[y])
		return (0);
	if (x < 0 || y < 0 
		|| x >= game->map->w
		|| y >= game->map->h)
		return (0);
	if (game->map->grid[y][x] == '1')
		return (0);
	return (1);
}

static void	move_player(t_game *game, int x, int y)
{
	char	*tile;

	tile = &game->map->grid[y][x];
	if (game->player_x != x || game->player_y != y)
	{
		game->player_x = x;
		game->player_y = y;
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
		error_exit("You Win!", game);
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
	{
		cleanup(game);
		exit(EXIT_SUCCESS);
	}
	if (can_move_to(game, x, y))
	{
		move_player(game, x, y);
		render_tile(game);
	}
	return (0);
}
