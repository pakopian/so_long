/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pakopian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 19:15:34 by pakopian          #+#    #+#             */
/*   Updated: 2025/02/03 13:00:08 by pakopian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_count(const char *s, char c)
{
	size_t	count;
	size_t	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			++count;
			in_word = 1;
		}
		else if (*s == c)
			in_word = 0;
		++s;
	}
	return (count);
}

static void	free_all(char **result, size_t i)
{
	size_t	j;

	j = 0;
	while (j < i)
	{
		free(result[j]);
		j++;
	}
	free(result);
}

static char	**fill_words(char **result, const char *s, char c)
{
	size_t	i;
	char	*start;

	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		start = (char *)s;
		while (*s && *s != c)
			s++;
		if (start != s)
		{
			result[i] = ft_substr(start, 0, s - start);
			if (!result[i])
				return (free_all(result, i), NULL);
			i++;
		}
	}
	result[i] = NULL;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	words;

	if (!s)
		return (NULL);
	words = word_count(s, c);
	result = ft_calloc(words + 1, sizeof(char *));
	if (!result)
		return (NULL);
	return (fill_words(result, s, c));
}
