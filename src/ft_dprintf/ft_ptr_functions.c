/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsemenov <dsemenov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:39:16 by tsargsya          #+#    #+#             */
/*   Updated: 2025/05/18 19:13:50 by dsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"
#include <stddef.h>
#include <unistd.h>

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
