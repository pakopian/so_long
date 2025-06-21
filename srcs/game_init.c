/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pakopian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 20:22:49 by pakopian          #+#    #+#             */
/*   Updated: 2025/06/10 20:22:51 by pakopian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "libft.h"

void	init_player_coords(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			if (game->map.data[y][x] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

static void	*load_img(t_game *game, char *path)
{
	int		w;
	int		h;
	void	*img;

	img = mlx_xpm_file_to_image(game->mlx, path, &w, &h);
	if (!img)
	{
		write(2, "Error\nFailed to load texture\n", 30);
		free_game(game);
		exit(1);
	}
	return (img);
}

int	init_textures(t_game *game)
{
	game->img_wall = load_img(game, "textures/wall.xpm");
	game->img_floor = load_img(game, "textures/floor.xpm");
	game->img_collectible = load_img(game, "textures/collectible.xpm");
	game->img_exit = load_img(game, "textures/exit.xpm");
	game->img_player = load_img(game, "textures/player.xpm");
	return (0);
}

int	init_game(t_game *game, char *file)
{
	game->tile_size = 64;
	game->mlx = mlx_init();
	if (!game->mlx)
		return (write(2, "Error\nMLX init failed\n", 23), 1);
	if (!read_map(file, &game->map))
		return (write(2, "Error\nInvalid map file\n", 24), 1);
	if (!validate_map(&game->map))
		return (1);
	init_player_coords(game);
	game->win = mlx_new_window(game->mlx,
			game->map.width * game->tile_size,
			game->map.height * game->tile_size,
			"So Long");
	if (!game->win)
		return (write(2, "Error\nWindow creation failed\n", 30), 1);
	return (init_textures(game));
}
