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

#include "game.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (write(2, "Error\nUsage: ./so_long map.ber\n", 32), 1);
	init_game_struct(&game);
	if (init_game(&game, argv[1]))
		exit_with_error(&game, NULL);
	render_map(&game);
	mlx_hook(game.win, 2, 1L << 0, key_hook, &game);
	mlx_hook(game.win, 17, 0, exit_hook, &game);
	mlx_loop(game.mlx);
	return (0);
}
