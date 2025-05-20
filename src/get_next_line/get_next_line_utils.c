/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsargsya <tsargsya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 18:07:00 by tsargsya          #+#    #+#             */
/*   Updated: 2025/05/20 23:21:27 by tsargsya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * @brief Joins two strings until a newline character is found.
 * @param line The original line.
 * @param buffer The buffer to join.
 * @return The newly allocated string, or NULL on error.
 */
char	*strjoin_till_nl(char *line, char *buffer)
{
	char	*str;
	size_t	size;
	size_t	i;
	size_t	j;

	i = 0;
	if (!line || !buffer)
		return (NULL);
	j = ft_strlen(line);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	size = i + j;
	str = malloc((size + 1) * sizeof(char));
	if (!str)
		return (free(line), NULL);
	ft_memcpy(str, line, j);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		str[j++] = buffer[i++];
	if (buffer[i] == '\n')
		str[j++] = buffer[i++];
	str[j] = '\0';
	return (free(line), str);
}
