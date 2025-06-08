/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pakopian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 09:58:23 by pakopian          #+#    #+#             */
/*   Updated: 2025/02/03 22:35:09 by pakopian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*result;
	size_t	len;

	len = ft_strlen(s) + 1;
	result = NULL;
	while (len--)
	{
		if (*s == (char)c)
			result = (char *)s;
		++s;
	}
	return (result);
}
