/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsargsya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:04:32 by tsargsya          #+#    #+#             */
/*   Updated: 2024/12/12 19:14:46 by tsargsya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	get_num_len(int n)
{
	size_t			len;
	unsigned int	buffer;

	len = 0;
	if (n < 0)
	{
		buffer = n * -1;
		len++;
	}
	else
	{
		buffer = n;
	}
	while (buffer >= 10)
	{
		len++;
		buffer /= 10;
	}
	len++;
	return (len);
}

char	*ft_itoa(int n)
{
	size_t			length;
	char			*str;
	size_t			i;
	unsigned int	buffer;

	length = get_num_len(n);
	str = malloc(length * sizeof (char) + 1);
	if (!str)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		buffer = n * -1;
	}
	else
		buffer = n;
	i = 0;
	str[length] = '\0';
	while (i < length && str[(length - 1) - i] != '-')
	{
		str[(length - 1) - i] = buffer % 10 + '0';
		buffer /= 10;
		i++;
	}
	return (str);
}
