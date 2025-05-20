/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsargsya <tsargsya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:48:33 by tsargsya          #+#    #+#             */
/*   Updated: 2025/05/20 22:09:16 by tsargsya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Locates the last occurrence of the character c in the string s.
 * @param s The string to search in.
 * @param c The character to locate.
 * @return A pointer to the last occurrence of c in s, or NULL if not found.
 */
char	*ft_strrchr(const char *s, int c)
{
	char	*tmp;

	tmp = 0;
	while (*s)
	{
		if (*s == (char) c)
			tmp = (char *) s;
		s++;
	}
	if ((char) c == 0)
		return ((char *) s);
	return (tmp);
}
