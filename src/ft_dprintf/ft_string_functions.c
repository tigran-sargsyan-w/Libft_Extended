/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsemenov <dsemenov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:49:03 by tsargsya          #+#    #+#             */
/*   Updated: 2025/05/18 19:14:26 by dsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

ssize_t	ft_putchar_fd(int fd, char c)
{
	if (write(fd, &c, 1) == -1)
		return (-1);
	return (1);
}

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
