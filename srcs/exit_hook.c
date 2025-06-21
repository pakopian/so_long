/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pakopian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 18:12:17 by pakopian          #+#    #+#             */
/*   Updated: 2025/06/11 18:12:18 by pakopian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	exit_hook(t_game *g)
{
	free_game(g);
	exit(0);
}

int	exit_with_error(t_game *g, char *msg)
{
	if (msg)
		write(2, msg, ft_strlen(msg));
	if (g)
		free_game(g);
	exit(1);
}
