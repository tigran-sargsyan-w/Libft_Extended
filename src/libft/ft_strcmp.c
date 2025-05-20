/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsargsya <tsargsya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 18:26:04 by tsargsya          #+#    #+#             */
/*   Updated: 2025/05/20 22:06:39 by tsargsya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Compares two strings lexicographically.
 * @param s1 The first string to compare.
 * @param s2 The second string to compare.
 * @return A negative value if s1 < s2, a positive value if s1 > s2, 
 * 			or 0 if they are equal.
 */
int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
