/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyungkim <kyungkim@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 22:46:55 by kyungkim          #+#    #+#             */
/*   Updated: 2025/01/10 00:43:25 by kyungkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

void	line_extract(char *buffer, char* line, int i)
{
	line = malloc(i + 2);
	if (!line)
	{
		free(buffer);
		return ;
	}
	memcopy(line, buffer, i + 1);
	line[check_newline(buffer) + 1] = '\0';
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
	memcopy(left, buffer + i + 1, left_i - 1);
	left[left_i - 1] = '\0';
	return (left);
}


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

