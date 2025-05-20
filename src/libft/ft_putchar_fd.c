/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsargsya <tsargsya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:07:03 by tsargsya          #+#    #+#             */
/*   Updated: 2025/05/20 22:03:05 by tsargsya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/**
 * @brief Writes a character to the specified file descriptor.
 * @param fd The file descriptor to write to.
 * @param c The character to write.
 * @return 1 on success, -1 on error.
 */
ssize_t	ft_putchar_fd(int fd, char c)
{
	if (write(fd, &c, 1) == -1)
		return (-1);
	return (1);
}
