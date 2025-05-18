/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsemenov <dsemenov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 12:17:03 by tsargsya          #+#    #+#             */
/*   Updated: 2025/05/18 19:15:53 by dsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"
#include <stdarg.h>
#include <unistd.h>

static ssize_t	ft_process(int fd, const char **format, va_list args);
static int		ft_parse(int fd, va_list args, const char c);

int	ft_dprintf(int fd, const char *format, ...)
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
		result = ft_process(fd, &format, args);
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

static ssize_t	ft_process(int fd, const char **format, va_list args)
{
	if (**format != '%')
		return (ft_putchar_fd(fd, **format));
	(*format)++;
	if (**format == '%')
		return (ft_putchar_fd(fd, '%'));
	return (ft_parse(fd, args, **format));
}

static int	ft_parse(int fd, va_list args, const char c)
{
	ssize_t	res;

	if (c == 'c')
		res = ft_putchar_fd(fd, va_arg(args, int));
	else if (c == 's')
		res = ft_dputstr(fd, va_arg(args, char *));
	else if (c == 'd' || c == 'i')
		res = ft_dputnbr(fd, va_arg(args, int));
	else if (c == 'u')
		res = ft_unsigned_dputnbr(fd, va_arg(args, unsigned int));
	else if (c == 'x')
		res = ft_dputhex(fd, va_arg(args, unsigned int), "0123456789abcdef");
	else if (c == 'X')
		res = ft_dputhex(fd, va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (c == 'p')
		res = ft_dputptr(fd, va_arg(args, void *));
	else
		res = 0;
	if (res == -1)
		return (-1);
	return (res);
}
