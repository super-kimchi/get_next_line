/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyungkim <kyungkim@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 20:44:44 by kyungkim          #+#    #+#             */
/*   Updated: 2025/01/28 01:37:33 by kyungkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>

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

static char	*eof_extract(char **buffer)
{
	char	*line;
	int		rest_l;

	rest_l = gnl_strlen(*buffer);
	if (rest_l != 0)
	{
		line = malloc(rest_l + 1);
		if (!line)
		{
			free(*buffer);
			*buffer = 0;
			return (0);
		}
		gnl_memcpy(line, *buffer, rest_l);
		line[rest_l] = '\0';
		free(*buffer);
		*buffer = 0;
		return (line);
	}
	else
		free(*buffer);
	*buffer = 0;
	return (0);
}

static int	ft_read(char **buffer, int fd)
{
	char	*temp;
	ssize_t	read_i;

	temp = malloc(BUFFER_SIZE + 1);
	read_i = read(fd, temp, BUFFER_SIZE);
	if (read_i == -1)
	{
		free(*buffer);
		free(temp);
		*buffer = 0;
		return (-1);
	}
	else if (read_i == 0)
	{
		free(temp);
		return (0);
	}
	temp[read_i] = '\0';
	*buffer = ft_strjoin_free(*buffer, temp);
	if (!*buffer)
		return (-1);
	return (1);
}

t_fdlist *check_node(t_fdlist *nodelist, int fd)
{
	t_fdlist *node;

	if (!nodelist)
	{
		node = malloc(sizeof(t_fdlist));
	if (!node)
			return (0);
		node->fd = fd;
		node->buffer = check_buffer(node->buffer);
		if (!node->buffer)
		{
			free(node);
			return (0);
		}
		return (node);
	}
	return (nodelist);
}

t_fdlist *find_node(t_fdlist *node, int fd)
{
	t_fdlist	*newnode;

	while (node->next)
	{
		if(node->fd == fd)
			return (node);
		node = node->next;
	}
	if (node->fd == fd)
		return (node);
	newnode = malloc(sizeof(t_fdlist));
	if (!newnode)
		return (0);
	newnode->fd = fd;
	newnode->buffer = check_buffer(newnode->buffer);
	if (!newnode->buffer)
	{
		free(newnode);
		return (0);
	}
	node->next = newnode;
	return (newnode);
}
	
char	*get_next_line(int fd)
{
	static t_fdlist	*head;
	t_fdlist		*node;
	int				read_check;

	head = check_node(head, fd);
	node = find_node(head, fd);
	if (!head)
		return (0);
	if (check_newline(node->buffer) != -1)
		return (gnl_split(&(node->buffer), check_newline(node->buffer)));
	while (check_newline(node->buffer) == -1)
	{
		read_check = ft_read(&(node->buffer), fd);
		if (read_check == -1)
			return (0);
		else if (read_check == 0)
			return (eof_extract(&(node->buffer)));
	}
	return (gnl_split(&(node->buffer), check_newline(node->buffer)));
}
