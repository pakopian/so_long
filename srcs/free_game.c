/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pakopian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 18:13:55 by pakopian          #+#    #+#             */
/*   Updated: 2025/06/11 18:13:57 by pakopian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	free_game(t_game *g)
{
	if (g->map.data)
		free_map(g->map.data, g->map.height);
	if (g->img_wall)
		mlx_destroy_image(g->mlx, g->img_wall);
	if (g->img_floor)
		mlx_destroy_image(g->mlx, g->img_floor);
	if (g->img_collectible)
		mlx_destroy_image(g->mlx, g->img_collectible);
	if (g->img_exit)
		mlx_destroy_image(g->mlx, g->img_exit);
	if (g->img_player)
		mlx_destroy_image(g->mlx, g->img_player);
	if (g->win)
		mlx_destroy_window(g->mlx, g->win);
	if (g->mlx)
	{
		mlx_destroy_display(g->mlx);
		free(g->mlx);
	}
	get_next_line(-1);
}

void	init_game_struct(t_game *g)
{
	g->mlx = NULL;
	g->win = NULL;
	g->img_wall = NULL;
	g->img_floor = NULL;
	g->img_player = NULL;
	g->img_exit = NULL;
	g->img_collectible = NULL;
	g->map.data = NULL;
	g->map.width = 0;
	g->map.height = 0;
	g->map.player_count = 0;
	g->map.exit_count = 0;
	g->map.collectible_count = 0;
	g->map.player_x = 0;
	g->map.player_y = 0;
	g->steps = 0;
}
