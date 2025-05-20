/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsargsya <tsargsya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:00:23 by tsargsya          #+#    #+#             */
/*   Updated: 2025/05/20 22:11:06 by tsargsya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/**
 * @brief Allocates (with malloc(3)) and returns an empty string.
 * @return A pointer to the newly allocated empty string, or NULL if the
 *         allocation fails.
 */
static char	*ft_return_empty_str(void)
{
	char	*res;

	res = malloc(1);
	if (!res)
		return (NULL);
	res[0] = '\0';
	return (res);
}

/**
 * @brief Allocates (with malloc(3)) and returns a substring from the string s.
 *        The substring begins at index start and is of maximum size len.
 * @param s The string to extract the substring from.
 * @param start The starting index of the substring.
 * @param len The maximum length of the substring.
 * @return A pointer to the newly allocated substring, or NULL if the allocation
 *         fails or if s is NULL.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	s_len;
	size_t	substr_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_return_empty_str());
	substr_len = s_len - start;
	if (substr_len > len)
		substr_len = len;
	res = malloc(substr_len + 1);
	if (!res)
		return (NULL);
	ft_strlcpy(res, s + start, substr_len + 1);
	return (res);
}
