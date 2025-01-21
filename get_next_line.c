/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyungkim <kyungkim@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 22:46:37 by kyungkim          #+#    #+#             */
/*   Updated: 2025/01/20 23:33:40 by kyungkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *check_buffer(char *buffer)
{
	char *new_buffer;

	if (!buffer)
	{
		new_buffer = malloc(1);
		if (!new_buffer)
			return (0);
		*new_buffer = '\0';
		return (new_buffer);
	}
	return (buffer);
}

static int	check_newline(char *buffer)
{
	int	i;
	
	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static char *extract_newline(char **buffer, int i)
{
	char	*line;

	line = line_extract(*buffer, i);
	if (!line)
		return (0);
	*buffer = leftover(*buffer, line, i);
	if (!*buffer)
		return (0);
	return (line);
}

static char *eof_extract(char *buffer)
{
	char *line;

	if (gnl_strlen(buffer) != 0)
	{
		line = line_extract(buffer, gnl_strlen(buffer) - 1);
		free(buffer);
		return (line);
	}
	else
		free(buffer);
	return (0);
}

char *get_next_line(int fd)
{
	static char *buffer = "hi\nkay";
	char	*temp;
	ssize_t read_i;
	
	buffer = check_buffer(&buffer);
	if (!buffer)
		return (0);
	if (check_newline(buffer) != -1)
		return (extract_newline(&buffer),check_newline(buffer));
	while (check_newline(buffer) == -1)
	{
		temp = malloc(BUFFER_SIZE + 1);
		read_i = read(fd, temp, BUFFER_SIZE);
		if (read_i == -1)
		{
			free(buffer);
			return (0);
		}
		else if (read_i == 0)
			return (eof_extract(buffer));
		else 
			buffer = ft_strjoin(buffer, temp);
	}
	return (extract_newline(&buffer));
}
