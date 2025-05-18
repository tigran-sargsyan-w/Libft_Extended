/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsemenov <dsemenov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 12:18:42 by tsargsya          #+#    #+#             */
/*   Updated: 2025/05/18 19:14:15 by dsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DPRINTF_H
# define FT_DPRINTF_H

# include <unistd.h>

int				ft_dprintf(int fd, const char *format, ...);
ssize_t			ft_putchar_fd(int fd, char c);
ssize_t			ft_dputstr(int fd, char *s);
ssize_t			ft_dputnbr(int fd, int n);
ssize_t			ft_unsigned_dputnbr(int fd, unsigned int n);
ssize_t			ft_dputhex(int fd, unsigned long nbr, const char *base);
ssize_t			ft_dputptr(int fd, void *ptr);

#endif
