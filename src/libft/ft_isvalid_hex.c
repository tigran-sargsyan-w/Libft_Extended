/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isvalid_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsargsya <tsargsya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 11:00:11 by tsargsya          #+#    #+#             */
/*   Updated: 2025/03/18 11:17:02 by tsargsya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isvalid_hex(const char *str)
{
	while (*str && ft_isspace(*str))
		str++;
	if (str[0] == '0' && (str[1] == 'x' || str[1] == 'X'))
		str += 2;
	if (!ft_isxdigit(*str))
		return (0);
	while (*str && !ft_isspace(*str) && *str != ',')
	{
		if (!ft_isxdigit(*str))
			return (0);
		str++;
	}
	return (1);
}
