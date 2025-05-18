/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsemenov <dsemenov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:53:38 by tsargsya          #+#    #+#             */
/*   Updated: 2025/05/18 19:16:40 by dsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"
#include <unistd.h>

static ssize_t	ft_dputnbr_recursive(int fd, unsigned int nbr)
{
	ssize_t	len;
	ssize_t	res;

	len = 0;
	if (nbr >= 10)
	{
		res = ft_dputnbr_recursive(fd, (nbr / 10));
		if (res == -1)
			return (-1);
		len += res;
	}
	if (ft_putchar_fd(fd, (nbr % 10) + '0') == -1)
		return (-1);
	len += 1;
	return (len);
}

ssize_t	ft_dputnbr(int fd, int n)
{
	ssize_t			len;
	unsigned int	nbr;

	len = 0;
	if (n == -2147483648)
		return (ft_dputstr(fd, "-2147483648"));
	if (n < 0)
	{
		if (ft_putchar_fd(fd, '-') == -1)
			return (-1);
		nbr = -n;
		len += 1;
	}
	else
		nbr = n;
	len += ft_dputnbr_recursive(fd, nbr);
	if (len == -1)
		return (-1);
	return (len);
}

ssize_t	ft_dputhex(int fd, unsigned long nbr, const char *base)
{
	ssize_t	len;
	ssize_t	res;

	len = 0;
	if (nbr >= 16)
	{
		res = ft_dputhex(fd, (nbr / 16), base);
		if (res == -1)
			return (-1);
		len += res;
	}
	if (ft_putchar_fd(fd, (base[nbr % 16])) == -1)
		return (-1);
	len += 1;
	return (len);
}

ssize_t	ft_unsigned_dputnbr(int fd, unsigned int nbr)
{
	ssize_t	len;
	ssize_t	res;

	len = 0;
	if (nbr >= 10)
	{
		res = ft_unsigned_dputnbr(fd, (nbr / 10));
		if (res == -1)
			return (-1);
		len += res;
	}
	if (ft_putchar_fd(fd, ((nbr % 10) + '0') == -1))
		return (-1);
	len += 1;
	return (len);
}
