/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsargsya <tsargsya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 12:11:12 by tsargsya          #+#    #+#             */
/*   Updated: 2025/05/24 12:14:23 by tsargsya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/**
 * @brief Duplicates the first n characters of the string s.
 * @param s The string to duplicate.
 * @param n The maximum number of characters to copy.
 * @return A pointer to the newly allocated string, or NULL if allocation fails.
 */
char	*ft_strndup(const char *s, size_t n)
{
	size_t	len;
	char	*dup;

	len = ft_strlen(s);
	if (len > n)
		len = n;
	dup = malloc(len + 1);
	if (!dup)
		return (NULL);
	ft_memcpy(dup, s, len);
	dup[len] = '\0';
	return (dup);
}
