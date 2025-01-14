/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyungkim <kyungkim@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 22:47:07 by kyungkim          #+#    #+#             */
/*   Updated: 2025/01/14 17:03:20 by kyungkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# define BUFFER_SIZE 42;

char	*get_next_line(int fd); 
int		check_newline(char *buffer);
char	*leftover(char *buffer, char *line, int i);
char	*line_extract(char *buffer, int i);

#endif
