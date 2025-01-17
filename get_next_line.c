/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyungkim <kyungkim@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 22:46:37 by kyungkim          #+#    #+#             */
/*   Updated: 2025/01/17 01:29:30 by kyungkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	static char *buffer = "hi\nkay";
	char	*line;
	
	buffer = check_buffer(&buffer);
	if (!buffer)
		return (0);
	if (check_newline2(
//	int		new_i;

//	(void) fd;
	else
	{
		new_i = check_newline(buffer);
		if (new_i != -1)
		{
			line = line_extract(buffer, new_i);
			buffer = leftover(buffer, line, new_i);
			if(!buffer)
				return (0);
			return (line);
		}
		else
		{
				
		}
	}
	return (0);
}

char *check_buffer(char *buffer)
{
	if (!buffer)
	{
		buffer = malloc(1);
		if (!*buffer)
			return (0);
		*buffer = '\0';
	}
	return (buffer);
}

