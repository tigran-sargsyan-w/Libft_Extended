/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isvalid_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsargsya <tsargsya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 11:00:00 by tsargsya          #+#    #+#             */
/*   Updated: 2025/05/20 21:55:43 by tsargsya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

/**
 * @brief Checks if the given string contains digits and checks for overflow.
 * @param str The string to check.
 * @param sign The sign of the number (-1 for negative, 1 for positive).
 * @return 1 if the string is valid, 0 otherwise.
 */
static int	check_overflow_digits(const char *str, int sign)
{
	long	result;

	result = 0;
	while (*str && !ft_isspace(*str) && *str != ',')
	{
		if (!ft_isdigit(*str))
			return (0);
		result = result * 10 + (*str - '0');
		if (sign == 1 && result > INT_MAX)
			return (0);
		if (sign == -1 && - result < INT_MIN)
			return (0);
		str++;
	}
	return (1);
}

/**
 * @brief Checks if the given string is a valid integer.
 * @param str The string to check.
 * @return 1 if the string is a valid integer, 0 otherwise.
 */
int	ft_isvalid_int(const char *str)
{
	int	sign;

	sign = 1;
	while (*str && ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (!ft_isdigit(*str))
		return (0);
	return (check_overflow_digits(str, sign));
}
