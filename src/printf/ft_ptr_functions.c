/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsargsya <tsargsya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:39:16 by tsargsya          #+#    #+#             */
/*   Updated: 2025/05/20 23:17:47 by tsargsya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief Writes a pointer to a file descriptor.
 * @param fd The file descriptor to write to.
 * @param ptr The pointer to write.
 * @return The number of characters written, or -1 on error.
 */
ssize_t	ft_dputptr(int fd, void *ptr)
{
	ssize_t	len;
	ssize_t	res;

	len = 0;
	if (ptr == NULL)
		return (ft_dputstr(fd, "(nil)"));
	len = ft_dputstr(fd, "0x");
	if (len == -1)
		return (-1);
	res = ft_dputhex(fd, (unsigned long)ptr, "0123456789abcdef");
	if (res == -1)
		return (-1);
	len += res;
	return (len);
}
