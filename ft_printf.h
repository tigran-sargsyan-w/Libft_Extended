/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsargsya <tsargsya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 12:18:42 by tsargsya          #+#    #+#             */
/*   Updated: 2025/05/20 21:43:11 by tsargsya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stddef.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		ft_dprintf(int fd, const char *format, ...);
ssize_t	ft_process_fd(int fd, const char **format, va_list args);
ssize_t	ft_dputstr(int fd, char *s);
ssize_t	ft_dputnbr(int fd, int n);
ssize_t	ft_unsigned_dputnbr(int fd, unsigned int n);
ssize_t	ft_dputhex(int fd, unsigned long nbr, const char *base);
ssize_t	ft_dputptr(int fd, void *ptr);

#endif
