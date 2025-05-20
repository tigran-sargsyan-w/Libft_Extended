/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsargsya <tsargsya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:03:15 by tsargsya          #+#    #+#             */
/*   Updated: 2025/05/20 22:05:33 by tsargsya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/**
 * @brief Counts the number of words in a string separated by a given character.
 * @param str The string to count words in.
 * @param separator The character used as the separator.
 * @return The number of words in the string.
 */
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

/**
 * @brief Frees all allocated memory for the array of strings.
 * @param tab The array of strings to free.
 * @param words_count The number of strings in the array.
 */
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

/**
 * @brief Splits a string into an array of strings using a specified separator.
 * @param s The string to split.
 * @param c The character used as the separator.
 * @return An array of strings (tokens) or NULL if the allocation fails.
 */
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
