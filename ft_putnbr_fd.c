/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsargsya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:11:42 by tsargsya          #+#    #+#             */
/*   Updated: 2024/12/13 15:30:15 by tsargsya         ###   ########.fr       */
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
		ft_putchar_fd('-', fd);
	}
	if (tmp >= 10)
	{
		ft_putnbr_fd(tmp / 10, fd);
	}
	ft_putchar_fd(tmp % 10 + '0', fd);
}
