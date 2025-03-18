/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isvalid_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsargsya <tsargsya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 11:00:00 by tsargsya          #+#    #+#             */
/*   Updated: 2025/03/18 11:16:51 by tsargsya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isvalid_int(const char *str)
{
	while (*str && ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
		str++;
	if (!ft_isdigit(*str))
		return (0);
	while (*str && !ft_isspace(*str) && *str != ',')
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}
