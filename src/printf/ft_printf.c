/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsargsya <tsargsya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 12:17:03 by tsargsya          #+#    #+#             */
/*   Updated: 2025/05/20 23:17:21 by tsargsya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief Writes formatted output to the standard output.
 * @param format The format string.
 * @param ... Arguments for the format string.
 * @return The number of characters written, or -1 on error.
 */
int	ft_printf(const char *format, ...)
{
	ssize_t	len;
	ssize_t	result;
	va_list	args;

	len = 0;
	if (!format)
	{
		return (-1);
	}
	va_start(args, format);
	while (*format)
	{
		result = ft_process_fd(1, &format, args);
		if (result == -1)
		{
			va_end(args);
			return (-1);
		}
		len += result;
		format++;
	}
	va_end(args);
	return (len);
}
