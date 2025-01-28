/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyungkim <kyungkim@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 20:37:06 by kyungkim          #+#    #+#             */
/*   Updated: 2025/01/27 23:57:05 by kyungkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>

typedef struct linkedlist
{
	int					fd;
	char				*buffer;
	struct linkedlist	*next;
}	t_fdlist;
void	gnl_memcpy(void *dest, void *src, int i);
int		gnl_strlen(char *str);
char	*ft_strjoin_free(char *src1, char *src2);
char	*gnl_split(char **buffer, int i);
char	*get_next_line(int fd);
#endif
