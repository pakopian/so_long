/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pakopian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 19:08:42 by pakopian          #+#    #+#             */
/*   Updated: 2025/06/08 19:08:44 by pakopian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int	main(int argc, char **argv)
{
	t_map	map;

	if (argc != 2)
	{
		write(2, "Usage: ./so_long map.ber\n", 26);
		return (1);
	}
	if (!read_map(argv[1], &map))
		return (1);
	if (!validate_map(&map))
	{
		free_map(map.data, map.height);
		return (1);
	}
	ft_printf("Map OK. Size: %d x %d\n", map.width, map.height);
	free_map(map.data, map.height);
	return (0);
}
