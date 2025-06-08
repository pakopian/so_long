/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read_fill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pakopian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 19:02:05 by pakopian          #+#    #+#             */
/*   Updated: 2025/06/08 19:02:07 by pakopian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static int	is_valid_char(char c)
{
	if (c == '0' || c == '1' || c == 'P' || c == 'E' || c == 'C')
		return (1);
	return (0);
}

static int	line_has_only_valid_chars(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
	{
		if (!is_valid_char(line[i]))
			return (0);
		i++;
	}
	return (1);
}

int	fill_map_data(int fd, t_map *map)
{
	int		i;
	char	*line;

	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (!line_has_only_valid_chars(line))
			return (free(line), 0);
		map->data[i] = line;
		i++;
		line = get_next_line(fd);
	}
	map->data[i] = NULL;
	close(fd);
	return (1);
}
