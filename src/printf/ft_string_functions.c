/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsargsya <tsargsya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:49:03 by tsargsya          #+#    #+#             */
/*   Updated: 2025/05/20 23:17:56 by tsargsya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief Writes a string to a file descriptor.
 * @param fd The file descriptor to write to.
 * @param s The string to write.
 * @return The number of characters written, or -1 on error.
 */
ssize_t	ft_dputstr(int fd, char *s)
{
	ssize_t	len;
	ssize_t	result;

	len = 0;
	if (!s)
		s = "(null)";
	while (*s)
	{
		result = ft_putchar_fd(fd, *s);
		if (result == -1)
			return (-1);
		len += result;
		s++;
	}
	return (len);
}
