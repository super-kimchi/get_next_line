/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyungkim <kyungkim@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 22:46:37 by kyungkim          #+#    #+#             */
/*   Updated: 2025/01/07 23:14:14 by kyungkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	static char *buffer;
	char	*line;

	if (!buffer)
	{
		buffer = malloc(1);
		if (!buffer)
			return (0);
		*buffer = '\0';
	}
	else if
	{
		if (check_newline(buffer))
		{
			line = malloc(check_newline(buffer) + 1);
			if (!line)
			{
				free(buffer);
				return (0);
			}


	}
}

