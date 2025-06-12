/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsargsya <tsargsya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:04:32 by tsargsya          #+#    #+#             */
/*   Updated: 2025/06/12 15:23:26 by tsargsya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/**
 * @brief Calculates the length of the number in digits.
 * @param n The integer to calculate the length for.
 * @return The length of the number in digits.
 */
static size_t	get_num_len(int n)
{
	size_t			len;
	unsigned int	buffer;

	len = 0;
	if (n < 0)
	{
		buffer = n * -1;
		len++;
	}
	else
	{
		buffer = n;
	}
	while (buffer >= 10)
	{
		len++;
		buffer /= 10;
	}
	len++;
	return (len);
}

/**
 * @brief Converts an integer to a string representation.
 * @param n The integer to convert.
 * @return A pointer to the string representation of the integer.
 */
char	*ft_itoa(int n)
{
	size_t			len;
	char			*str;
	size_t			i;
	unsigned int	buf;

	len = get_num_len(n);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n < 0)
		buf = -n;
	else
		buf = n;
	i = len - 1;
	if (buf == 0)
		str[i--] = '0';
	while (buf > 0)
	{
		str[i--] = buf % 10 + '0';
		buf /= 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
