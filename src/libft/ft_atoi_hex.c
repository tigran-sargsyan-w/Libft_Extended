/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsargsya <tsargsya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 19:38:25 by tsargsya          #+#    #+#             */
/*   Updated: 2025/05/20 21:47:31 by tsargsya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Converts a hexadecimal string to an integer.
 * @param str The hexadecimal string to convert.
 * @return The converted integer value.
 */
int	ft_atoi_hex(const char *str)
{
	int	result;

	result = 0;
	if (str[0] == '0' && (str[1] == 'x' || str[1] == 'X'))
		str += 2;
	while (*str)
	{
		if (ft_isdigit(*str))
			result = result * 16 + (*str - '0');
		else if (ft_tolower(*str) >= 'a' && ft_tolower(*str) <= 'f')
			result = result * 16 + (ft_tolower(*str) - 'a' + 10);
		else
			break ;
		str++;
	}
	return (result);
}
