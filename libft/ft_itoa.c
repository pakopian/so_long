/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pakopian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:54:37 by pakopian          #+#    #+#             */
/*   Updated: 2025/02/03 20:18:08 by pakopian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*writing_str(int n, char *str)
{
	if (n < 0)
	{
		*str = '-';
		++str;
		n *= -1;
	}
	if (n >= 10)
		str = writing_str(n / 10, str);
	*str = (n % 10) + '0';
	str++;
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		nc;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	nc = n;
	i = 0;
	while (nc != 0)
	{
		++i;
		nc /= 10;
	}
	if (n < 0)
		++i;
	str = (char *)malloc((i + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[i] = '\0';
	writing_str(n, str);
	return (str);
}
