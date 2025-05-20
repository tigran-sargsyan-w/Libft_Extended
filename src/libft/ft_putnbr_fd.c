/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsargsya <tsargsya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:11:42 by tsargsya          #+#    #+#             */
/*   Updated: 2025/05/20 12:47:43 by tsargsya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	tmp;

	tmp = n;
	if (n < 0)
	{
		tmp = -tmp;
		ft_putchar_fd(fd, '-');
	}
	if (tmp >= 10)
	{
		ft_putnbr_fd(tmp / 10, fd);
	}
	ft_putchar_fd(fd, tmp % 10 + '0');
}
