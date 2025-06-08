/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pakopian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 19:02:13 by pakopian          #+#    #+#             */
/*   Updated: 2025/06/08 19:02:15 by pakopian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static int	check_rectangular(t_map *map)
{
	int		i;
	int		len;

	i = 0;
	while (i < map->height)
	{
		len = ft_strlen(map->data[i]);
		if (map->data[i][len - 1] == '\n')
			len--;
		if (len != map->width)
			return (0);
		i++;
	}
	return (1);
}

static int	check_walls(t_map *map)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			c = map->data[i][j];
			if ((i == 0 || i == map->height - 1) && c != '1')
				return (0);
			else if ((j == 0 || j == map->width - 1) && c != '1')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static void	count_elements(t_map *map)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	map->player_count = 0;
	map->exit_count = 0;
	map->collectible_count = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			c = map->data[i][j];
			if (c == 'P')
				map->player_count++;
			else if (c == 'E')
				map->exit_count++;
			else if (c == 'C')
				map->collectible_count++;
			j++;
		}
		i++;
	}
}

int	validate_map(t_map *map)
{
	if (!check_rectangular(map))
		return (write(2, "Error\nMap is not rectangular\n", 30), 0);
	if (!check_walls(map))
		return (write(2, "Error\nMap is not surrounded by walls\n", 37), 0);
	count_elements(map);
	if (map->player_count != 1 || map->exit_count != 1
		|| map->collectible_count < 1)
		return (write(2, "Error\nMap must have 1 P, 1 E, 1+ C\n", 34), 0);
	return (1);
}
