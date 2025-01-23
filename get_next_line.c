/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyungkim <kyungkim@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 22:46:37 by kyungkim          #+#    #+#             */
/*   Updated: 2025/01/23 00:51:05 by kyungkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*check_buffer(char *buffer)
{
	char	*new_buffer;

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
/*
static char	*extract_newline(char **buffer, int i)
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
*/
static char	*eof_extract(char *buffer, char *temp)
{
	char	*line;
	int		rest_l;
	
	free(temp);
	rest_l = gnl_strlen(buffer);
	if (rest_l != 0)
	{
		line = malloc(rest_l + 1);
		if (!line)
		{
			free(buffer);
			return (0);
		}
		gnl_memcpy(line, buffer, rest_l);
		line[rest_l] = '\0';
		free(buffer);
		return (line);
	}
	else
		free(buffer);
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*temp;
	ssize_t		read_i;

	buffer = check_buffer(buffer);
	if (!buffer)
		return (0);
	if (check_newline(buffer) != -1)
		return (gnl_split(&buffer, check_newline(buffer)));
//		return (extract_newline(&buffer), check_newline(buffer));
	while (check_newline(buffer) == -1)
	{
		temp = malloc(BUFFER_SIZE + 1);
		temp[BUFFER_SIZE] = '\0';
		read_i = read(fd, temp, BUFFER_SIZE);
		if (read_i == -1)
		{
			free(buffer);
			free(temp);
			return (0);
		}
		else if (read_i == 0)
			return (eof_extract(buffer, temp));
		else
		{
			buffer = ft_strjoin_free(buffer, temp);
			if (!buffer)
				return (0);
		}

	}
	return (gnl_split(&buffer, check_newline(buffer)));
	//return (extract_newline(&buffer));
}
