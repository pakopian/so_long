/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pakopian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 20:26:17 by pakopian          #+#    #+#             */
/*   Updated: 2025/06/10 20:26:20 by pakopian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static void	render_tile(t_game *g, char tile, int x, int y)
{
	void	*img;

	if (tile == '1')
		img = g->img_wall;
	else
		img = g->img_floor;
	mlx_put_image_to_window(g->mlx, g->win, img,
		x * g->tile_size, y * g->tile_size);
	if (tile == 'C')
		mlx_put_image_to_window(g->mlx, g->win, g->img_collectible,
			x * g->tile_size, y * g->tile_size);
	else if (tile == 'E')
		mlx_put_image_to_window(g->mlx, g->win, g->img_exit,
			x * g->tile_size, y * g->tile_size);
	else if (tile == 'P')
		mlx_put_image_to_window(g->mlx, g->win, g->img_player,
			x * g->tile_size, y * g->tile_size);
}

void	render_map(t_game *game)
{
	int		y;
	int		x;
	char	tile;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			tile = game->map.data[y][x];
			render_tile(game, tile, x, y);
			x++;
		}
		y++;
	}
}
