/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsargsya <tsargsya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:51:00 by tsargsya          #+#    #+#             */
/*   Updated: 2025/05/20 22:01:10 by tsargsya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/**
 * @brief Compares the first n bytes of the memory areas s1 and s2.
 * @param s1 The first memory area to compare.
 * @param s2 The second memory area to compare.
 * @param n The number of bytes to compare.
 * @return An integer less than, equal to, or greater than zero if the first
 *         n bytes of s1 is found to be less than, to match, or be greater
 *         than the first n bytes of s2.
 */
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	while (n)
	{
		if (*(unsigned char *) s1 != *(unsigned char *) s2)
			return ((int)(*(unsigned char *) s1 - *(unsigned char *) s2));
		s1++;
		s2++;
		n--;
	}
	return (0);
}
