/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsargsya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:03:15 by tsargsya          #+#    #+#             */
/*   Updated: 2024/12/12 18:07:33 by tsargsya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	get_word_count(char const *str, char separator)
{
	size_t	i;
	size_t	count;
	size_t	in_word;

	in_word = 0;
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != separator && !in_word)
		{
			in_word = 1;
			count++;
		}
		if (str[i] == separator)
			in_word = 0;
		i++;
	}
	return (count);
}

static void	*free_all(char **tab, size_t words_count)
{
	size_t	i;

	i = 0;
	while (i < words_count)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	words_count;
	size_t	word_length;
	size_t	word_index;

	words_count = get_word_count(s, c);
	res = malloc((words_count + 1) * sizeof (char *));
	if (!res)
		return (NULL);
	res[words_count] = NULL;
	word_index = 0;
	while (*s && word_index < words_count)
	{
		while (*s && *s == c)
			s++;
		word_length = 0;
		while (s[word_length] && s[word_length] != c)
			word_length++;
		res[word_index] = ft_substr(s, 0, word_length);
		if (!res[word_index])
			return (free_all(res, word_index));
		word_index++;
		s += word_length;
	}
	return (res);
}
