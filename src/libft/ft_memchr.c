/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsargsya <tsargsya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:50:24 by tsargsya          #+#    #+#             */
/*   Updated: 2025/05/20 22:00:46 by tsargsya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/**
 * @brief Locates the first occurrence of c (converted to an unsigned char)
 *        in the first n bytes of the string pointed to by s.
 * @param s The string to search.
 * @param c The character to locate.
 * @param n The number of bytes to search.
 * @return A pointer to the first occurrence of c in s, or NULL if c is not
 *         found in the first n bytes.
 */
void	*ft_memchr(const void *s, int c, size_t n)
{
	while (n)
	{
		if (*(unsigned char *) s == (unsigned char) c)
			return ((void *) s);
		s++;
		n--;
	}
	return (NULL);
}
