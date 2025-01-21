/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyungkim <kyungkim@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 22:47:07 by kyungkim          #+#    #+#             */
/*   Updated: 2025/01/20 23:35:13 by kyungkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# define BUFFER_SIZE 42;

void	gnl_memcpy(void *dest, void *src, int i);
int		gnl_strlen(char *str);
char	*ft_strjoin_free(char *src1, char *src2);
char	*line_extract(char *buffer, int i);
char	*leftover(char *buffer, char *line, int i);
char	*get_next_line(int fd); 

#endif
