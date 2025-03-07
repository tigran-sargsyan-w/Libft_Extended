/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_tokens.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsargsya <tsargsya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 15:36:38 by tsargsya          #+#    #+#             */
/*   Updated: 2025/03/07 15:37:36 by tsargsya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_count_tokens(char **tokens)
{
	int	count;

	count = 0;
	while (tokens[count] != NULL)
		count++;
	return (count);
}
