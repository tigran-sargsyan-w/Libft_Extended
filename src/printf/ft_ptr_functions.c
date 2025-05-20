/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsargsya <tsargsya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:39:16 by tsargsya          #+#    #+#             */
/*   Updated: 2025/05/20 21:43:16 by tsargsya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
