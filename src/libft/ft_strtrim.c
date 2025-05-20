/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsargsya <tsargsya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:02:08 by tsargsya          #+#    #+#             */
/*   Updated: 2025/05/20 22:10:34 by tsargsya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/**
 * @brief Finds the first index of a character in a string.
 * @param s1 The string to search in.
 * @param set The set of characters to search for.
 * @return The first index of a character in the string.
 */
static size_t	first_index(char const *s1, const char *set)
{
	size_t	i;

	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	return (i);
}

/**
 * @brief Finds the last index of a character in a string.
 * @param s1 The string to search in.
 * @param set The set of characters to search for.
 * @return The last index of a character in the string.
 */
static size_t	last_index(char const *s1, const char *set)
{
	size_t	i;

	i = ft_strlen(s1) - 1;
	while (i && ft_strchr(set, s1[i]))
		i--;
	return (i);
}

/**
 * @brief Allocates (with malloc(3)) and returns an empty string.
 * @return A pointer to the newly allocated empty string, or NULL if the
 *         allocation fails.
 */
static char	*empty_str(void)
{
	char	*str;

	str = malloc(1);
	if (!str)
		return (NULL);
	str[0] = '\0';
	return (str);
}

/**
 * @brief Allocates (with malloc(3)) and returns a copy of the string given as
 *        argument without the characters specified in the set at the beginning
 *        and at the end of the string.
 * @param s1 The string to be trimmed.
 * @param set The set of characters to trim from the beginning and end of s1.
 * @return A pointer to the newly allocated trimmed string, or NULL if the
 *         allocation fails.
 */
char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	size_t	i;
	size_t	start;
	size_t	end;

	if (!s1)
		return (NULL);
	i = 0;
	start = first_index(s1, set);
	end = last_index(s1, set);
	if (start > end || !*s1)
		return (empty_str());
	res = malloc(end - start + 2);
	if (!res)
		return (NULL);
	while (start <= end)
	{
		res[i] = s1[start];
		i++;
		start++;
	}
	res[i] = '\0';
	return (res);
}
