/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsargsya <tsargsya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 19:21:57 by tsargsya          #+#    #+#             */
/*   Updated: 2025/05/20 23:22:38 by tsargsya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*strdup_till_nl(char *str);
static char	*read_and_join(int fd, char *buffers, char *line);
static char	*handle_empty_line(char *buffers, char *line);
static void	shift_buffer_after_nl(char *buffer);

/**
 * @brief Duplicates a string until a newline character is found.
 * @param str The string to duplicate.
 * @return The newly allocated string, or NULL on error.
 */
static char	*strdup_till_nl(char *str)
{
	char	*dup;
	size_t	len;
	size_t	i;

	len = 0;
	i = 0;
	while (str[len] && str[len] != '\n')
		len++;
	if (str[len] == '\n')
		len++;
	dup = malloc(len + 1);
	if (!dup)
		return (NULL);
	while (i < len)
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

/**
 * @brief Reads from a file descriptor and joins the buffer to the line.
 * @param fd The file descriptor to read from.
 * @param buffers The buffer to read into.
 * @param line The line to join with the buffer.
 * @return The newly allocated string, or NULL on error.
 */
static char	*read_and_join(int fd, char *buffers, char *line)
{
	int	bytes;

	bytes = 1;
	while (bytes > 0 && !ft_strchr(line, '\n'))
	{
		bytes = read(fd, buffers, BUFFER_SIZE);
		if (bytes == -1)
		{
			buffers[0] = '\0';
			free(line);
			return (NULL);
		}
		buffers[bytes] = '\0';
		line = strjoin_till_nl(line, buffers);
		if (!line)
		{
			buffers[0] = '\0';
			return (NULL);
		}
	}
	return (line);
}

/**
 * @brief Handles the case where the line is empty.
 * @param buffers The buffer to check.
 * @param line The line to check.
 * @return The line if not empty, or NULL if empty.
 */
static char	*handle_empty_line(char *buffers, char *line)
{
	if (!line[0])
	{
		buffers[0] = '\0';
		free(line);
		return (NULL);
	}
	return (line);
}

/**
 * @brief Shifts the buffer after a newline character.
 * @param buffer The buffer to shift.
 */
static void	shift_buffer_after_nl(char *buffer)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	while (buffer[i])
	{
		buffer[j] = buffer[i];
		i++;
		j++;
	}
	buffer[j] = '\0';
}

/**
 * @brief Reads a line from a file descriptor.
 * @param fd The file descriptor to read from.
 * @return The line read, or NULL on error or end of file.
 */
char	*get_next_line(int fd)
{
	char		*line;
	static char	buffers[MAX_FD][BUFFER_SIZE + 1];

	if (fd < 0 || fd >= MAX_FD || BUFFER_SIZE <= 0)
		return (NULL);
	line = strdup_till_nl(buffers[fd]);
	if (!line)
	{
		buffers[fd][0] = '\0';
		return (NULL);
	}
	line = read_and_join(fd, buffers[fd], line);
	if (!line)
	{
		buffers[fd][0] = '\0';
		return (NULL);
	}
	line = handle_empty_line(buffers[fd], line);
	if (!line)
	{
		buffers[fd][0] = '\0';
		return (NULL);
	}
	shift_buffer_after_nl(buffers[fd]);
	return (line);
}
