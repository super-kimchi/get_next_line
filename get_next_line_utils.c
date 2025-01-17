/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyungkim <kyungkim@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 22:46:55 by kyungkim          #+#    #+#             */
/*   Updated: 2025/01/17 01:31:54 by kyungkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	memcopy(void *dest, void *src, int i)
{
	int c;

	c = 0;
	while (c < i)
	{
		((char *)dest)[c] = ((char *)src)[c];
		c++;
	}
}


char *check_newline2(char *buffer)
{
	int		i;
	char	*line;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
		{
			line = malloc(i + 2);
			if (!line)
			{
				free(buffer);
				return (0);
			}
			memcopy(line, buffer, i + 1);
			line[i + 1] = '\0';
			return (line);
		}
		i++;
	}
	return (0);
}


int	check_newline(char *buffer)
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

char	*line_extract(char *buffer, int i)
{
	char *line;

	line = malloc(i + 2);
	if (!line)
	{
		free(buffer);
		return (0);
	}
	memcopy(line, buffer, i + 1);
	line[i + 1] = '\0';
	return (line);
}

char	*leftover(char *buffer, char *line, int i)
{
	int		left_i;
	char	*left;

	left_i = 1;
	while (buffer[i + left_i])
		left_i++;
	left = malloc(left_i);
	if (!left)
	{
		free(buffer);
		free(line);
		return (0);
	}
	memcopy(left, buffer + i + 1, left_i);
	left[left_i - 1] = '\0';
	return (left);
}

char	*read_newline(char *buffer, int fd)
{
	char	*temp;
	ssize_t	read_i;

	temp = malloc(BUFFER_SIZE + 1);
	if (!temp)
	{
		free(buffer);
		return (0);
	}
	read_i = read(fd, buffer, BUFFER_SIZE);
	if (read_i == 
}



