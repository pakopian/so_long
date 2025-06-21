/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_solvable.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pakopian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 17:08:14 by pakopian          #+#    #+#             */
/*   Updated: 2025/06/12 17:08:16 by pakopian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "libft.h"

static void	flood_fill(t_map *map, char **copy, int x, int y)
{
	if (x < 0 || y < 0 || x >= map->width || y >= map->height)
		return ;
	if (copy[y][x] == '1' || copy[y][x] == 'F')
		return ;
	if (copy[y][x] == 'E')
	{
		copy[y][x] = 'F';
		return ;
	}
	copy[y][x] = 'F';
	flood_fill(map, copy, x + 1, y);
	flood_fill(map, copy, x - 1, y);
	flood_fill(map, copy, x, y + 1);
	flood_fill(map, copy, x, y - 1);
}

static void	free_map_copy(char **copy, int i)
{
	while (--i >= 0)
		free(copy[i]);
	free(copy);
}

static char	**copy_map(char **src, int height)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * (height + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < height)
	{
		copy[i] = ft_strdup(src[i]);
		if (!copy[i])
		{
			free_map_copy(copy, i);
			return (NULL);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

int	is_map_solvable(t_map *map)
{
	char	**copy;
	int		y;
	int		x;

	copy = copy_map(map->data, map->height);
	if (!copy)
		return (0);
	flood_fill(map, copy, map->player_x, map->player_y);
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (copy[y][x] == 'C' || copy[y][x] == 'E')
			{
				free_map(copy, map->height);
				return (0);
			}
			x++;
		}
		y++;
	}
	free_map(copy, map->height);
	return (1);
}
