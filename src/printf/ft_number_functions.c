/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsargsya <tsargsya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:53:38 by tsargsya          #+#    #+#             */
/*   Updated: 2025/05/20 23:19:08 by tsargsya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief Writes a number recursively to a file descriptor.
 * @param fd The file descriptor to write to.
 * @param nbr The number to write.
 * @return The number of characters written, or -1 on error.
 */
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

/**
 * @brief Writes an integer to a file descriptor.
 * @param fd The file descriptor to write to.
 * @param n The integer to write.
 * @return The number of characters written, or -1 on error.
 */
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

/**
 * @brief Writes a hexadecimal number to a file descriptor.
 * @param fd The file descriptor to write to.
 * @param nbr The hexadecimal number to write.
 * @param base The base string for hexadecimal representation.
 * @return The number of characters written, or -1 on error.
 */
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

/**
 * @brief Writes an unsigned integer to a file descriptor.
 * @param fd The file descriptor to write to.
 * @param nbr The unsigned integer to write.
 * @return The number of characters written, or -1 on error.
 */
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
	if (ft_putchar_fd(fd, (nbr % 10)) + '0' == -1)
		return (-1);
	len += 1;
	return (len);
}
