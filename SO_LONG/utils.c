/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foogungb <foogungb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 16:38:25 by foogungb          #+#    #+#             */
/*   Updated: 2025/08/04 16:38:26 by foogungb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "GetNextLine/get_next_line.h"

void	check_map(t_map *map)
{
	int	px;
	int	py;

	if (!find_player_position(map, &px, &py))
	{
		free_map_struct(map);
		error_exit("No player found on map.", NULL);
	}
	validate_map_solvability(map, px, py);
}

size_t	ft_strcspn(const char *s, const char *reject)
{
	const char	*str;
	const char	*r;

	str = s;
	while (*s)
	{
		r = reject;
		while (*r)
		{
			if (*s == *r)
				return (s - str);
			r++;
		}
		s++;
	}
	return (s - str);
}

int	get_map_height(const char *filename)
{
	int		fd;
	int		last_nline;
	int		height;
	char	c;

	last_nline = 0;
	height = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	while (read(fd, &c, 1) > 0)
	{
		if (c == '\n')
		{
			height++;
			last_nline = 1;
		}
		else
			last_nline = 0;
	}
	if (!last_nline)
		height++;
	if (close(fd) == -1)
		error_exit("Could not close file", NULL);
	return (height);
}

void	free_map(char **map, int lines)
{
	int	i;

	i = 0;
	while (i < lines)
		free(map[i++]);
	free(map);
}

void	free_map_struct(t_map *map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	if (map)
	{
		if (map->grid)
		{
			while (map->grid[i])
				free(map->grid[i++]);
			free(map->grid);
		}
		free(map);
	}
}
