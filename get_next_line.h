/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsargsya <tsargsya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 18:07:11 by tsargsya          #+#    #+#             */
/*   Updated: 2025/05/20 16:34:16 by tsargsya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>
# include "libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

# ifndef MAX_FD
#  define MAX_FD 1024
# endif

char	*get_next_line(int fd);
char	*strjoin_till_nl(char *line, char *buffer);
void	shift_buffer_after_nl(char *buffer);
char	*strdup_till_nl(char *str);
char	*read_and_join(int fd, char *buffers, char *line);
char	*handle_empty_line(char *buffers, char *line);

#endif