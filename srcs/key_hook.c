/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pakopian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 18:09:28 by pakopian          #+#    #+#             */
/*   Updated: 2025/06/11 18:09:33 by pakopian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "libft.h"

void	move_to(t_game *g, int new_x, int new_y)
{
	char	next;

	next = g->map.data[new_y][new_x];
	if (next == '1')
		return ;
	if (next == 'E')
	{
		if (g->map.collectible_count == 0)
		{
			ft_printf("You win in %d steps!\n", g->steps + 1);
			exit_hook(g);
		}
		return ;
	}
	if (next == 'C')
		g->map.collectible_count--;
	if (g->map.data[g->player_y][g->player_x] != 'E')
		g->map.data[g->player_y][g->player_x] = '0';
	g->player_x = new_x;
	g->player_y = new_y;
	if (g->map.data[new_y][new_x] != 'E')
		g->map.data[new_y][new_x] = 'P';
	g->steps++;
	ft_printf("Steps: %d\n", g->steps);
	render_map(g);
}

int	key_hook(int keycode, t_game *g)
{
	if (keycode == 65307)
		exit_hook(g);
	else if (keycode == 1751)
		move_to(g, g->player_x, g->player_y - 1);
	else if (keycode == 1747)
		move_to(g, g->player_x, g->player_y + 1);
	else if (keycode == 1729)
		move_to(g, g->player_x - 1, g->player_y);
	else if (keycode == 1732)
		move_to(g, g->player_x + 1, g->player_y);
	return (0);
}
