/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pakopian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 18:27:58 by pakopian          #+#    #+#             */
/*   Updated: 2025/02/03 23:00:01 by pakopian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	summ;

	summ = count * size;
	if (count && summ / count != size)
		return (NULL);
	ptr = malloc(summ);
	if (ptr)
		ft_bzero(ptr, summ);
	return (ptr);
}
