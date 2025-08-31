/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foogungb <foogungb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 16:38:25 by foogungb          #+#    #+#             */
/*   Updated: 2025/08/04 16:38:26 by foogungb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"
#include "GetNextLine/get_next_line.h"

char	**duplicate_map(char **grid, int height)
{
	char	**copy;
	int		i;
	int		j;

	i = 0;
	copy = (char **)malloc((height + 1) * (sizeof(char *)));
	if (!copy)
		return (NULL);
	while (i < height)
	{
		copy[i] = ft_strdup(grid[i]);
		if (!copy[i])
		{
			j = 0;
			while (j < i)
				free(copy[j++]);
			free(copy);
			return (NULL);
		}
		i++;
	}
	copy[height] = NULL;
	return (copy);
}

void	flood_fill(char **grid, int row, int col)
{
	int	width;

	if (row < 0 || col < 0 || !grid[row])
		return ;
	width = ft_strlen(grid[row]);
	if (col >= width)
		return ;
	if (grid[row][col] == '1' || grid[row][col] == 'V')
		return ;
	grid[row][col] = 'V';
	flood_fill(grid, row + 1, col);
	flood_fill(grid, row - 1, col);
	flood_fill(grid, row, col + 1);
	flood_fill(grid, row, col - 1);
}

int	has_unreachable_items(char **grid, int width, int height)
{
	int	row;
	int	col;

	row = 0;
	while (row < height)
	{
		col = 0;
		while (col < width)
		{
			if (grid[row][col] == 'C' || grid[row][col] == 'E')
				return (1);
			col++;
		}
		row++;
	}
	return (0);
}
