/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyungkim <kyungkim@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 22:46:55 by kyungkim          #+#    #+#             */
/*   Updated: 2025/01/21 00:01:12 by kyungkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	gnl_memcpy(void *dest, void *src, int i)
{
	int	c;

	c = 0;
	while (c < i)
	{
		((char *)dest)[c] = ((char *)src)[c];
		c++;
	}
}

int	gnl_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin_free(char *src1, char *src2)
{
	char	*final_str;
	int		i_1;
	int		i_2;

	i_1 = gnl_strlen(src1);
	i_2 = gnl_strlen(src2);
	final_str = malloc(i_1 + i_2 + 1);
	if (!final_str)
	{
		free(src1);
		free(src2);
		return (0);
	}
	gnl_memcpy(final_str, src1, i_1);
	gnl_memcpy(final_str[i_1], src2, i_2);
	final_str[i_1 + i_2 + 1] = '\0';
	free(src1);
	free(src2);
	return (final_str);
}

char	*gnl_split(char **buffer, int i)
{
	char	*line;
	char	*left;
	int		left_i;

	line = malloc(i + 2);
	if (!line)
	{
		free(*buffer);
		return (0);
	}
	gnl_memcpy(line, *buffer, i + 1);
	line[i + 1] = '\0';
	left_i = gnl_strlen(*buffer + i + 1);
	left = malloc(left_i);
	if (!left)
	{
		free(*buffer);
		free(line);
		return (0);
	}
	gnl_memcpy(left, buffer + i + 1, left_i - 1);
	left[left_i - 1] = '\0';
	free(*buffer);
	*buffer = left;
	return (line);
}

char	*line_extract(char *buffer, int i)
{
	char	*line;

	line = malloc(i + 2);
	if (!line)
	{
		free(buffer);
		return (0);
	}
	gnl_memcpy(line, buffer, i + 1);
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
	gnl_memcpy(left, buffer + i + 1, left_i - 1);
	left[left_i - 1] = '\0';
	free(buffer);
	return (left);
}
