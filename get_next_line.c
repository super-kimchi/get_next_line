/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyungkim <kyungkim@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 22:46:37 by kyungkim          #+#    #+#             */
/*   Updated: 2025/01/10 00:38:56 by kyungkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"



char *get_next_line(int fd)
{
	static char *buffer;
	char	*line;
	int		new_i;

	if (!buffer)
	{
		buffer = malloc(1);
		if (!buffer)
			return (0);
		*buffer = '\0';
	}
	else
	{
		new_i = check_newline(buffer);
		if (new_i != -1)
		{
			line_extract(buffer, line, new_i);
			buffer = leftover(buffer, line, new_i);
			return (line);
	}
}


