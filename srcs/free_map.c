/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pakopian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 19:06:32 by pakopian          #+#    #+#             */
/*   Updated: 2025/06/08 19:06:34 by pakopian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void	free_map(char **map, int height)
{
	int	i;

	if (map == NULL)
		return ;
	i = 0;
	while (i < height)
	{
		if (map[i] != NULL)
			free(map[i]);
		i++;
	}
	free(map);
}
