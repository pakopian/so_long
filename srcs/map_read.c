/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pakopian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 19:01:58 by pakopian          #+#    #+#             */
/*   Updated: 2025/06/08 19:02:00 by pakopian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static int	count_lines(int fd)
{
	int		count;
	char	*line;

	count = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	return (count);
}

int	read_map(const char *filename, t_map *map)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (write(2, "Error\nCannot open map file\n", 28), 0);
	map->height = count_lines(fd);
	close(fd);
	fd = open(filename, O_RDONLY);
	map->data = malloc(sizeof(char *) * (map->height + 1));
	if (map->data == NULL)
	{
		close(fd);
		return (write(2, "Error\nMalloc failed\n", 21), 0);
	}
	if (!fill_map_data(fd, map))
		return (close(fd), write(2,
				"Error\nInvalid characters in map\n", 32), 0);
	close(fd);
	if (!map->data[0])
		return (0);
	map->width = ft_strlen(map->data[0]);
	if (map->data[0][map->width - 1] == '\n')
		map->width--;
	return (1);
}
