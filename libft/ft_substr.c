/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pakopian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 16:18:03 by pakopian          #+#    #+#             */
/*   Updated: 2025/02/03 12:39:01 by pakopian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	substr_len;

	if (!s || start >= ft_strlen(s))
		return (ft_strdup(""));
	substr_len = ft_strlen(s) - start;
	if (substr_len > len)
		substr_len = len;
	substr = (char *)malloc((substr_len + 1) * sizeof(char));
	if (substr)
		ft_strlcpy(substr, s + start, substr_len + 1);
	return (substr);
}
