/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pakopian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 20:16:12 by pakopian          #+#    #+#             */
/*   Updated: 2025/06/10 20:16:15 by pakopian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "map.h"
# include "../mlx/mlx.h"

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_map	map;
	void	*img_wall;
	void	*img_floor;
	void	*img_collectible;
	void	*img_exit;
	void	*img_player;
	int		tile_size;
	int		player_x;
	int		player_y;
	int		steps;
	int		exit_x;
	int		exit_y;
}	t_game;

int		init_game(t_game *game, char *file);
void	init_player_coords(t_game *game);
int		init_textures(t_game *game);
void	render_map(t_game *game);
void	free_game(t_game *game);
int		key_hook(int keycode, t_game *g);
int		exit_hook(t_game *game);
int		is_map_solvable(t_map *map);
int		exit_with_error(t_game *g, char *msg);
void	init_game_struct(t_game *g);

#endif
