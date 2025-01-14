/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyungkim <kyungkim@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:26:46 by kyungkim          #+#    #+#             */
/*   Updated: 2025/01/14 15:34:55 by kyungkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	char *test = get_next_line(1);
	printf("test1 buffer:%s:", test);
	test = get_next_line(1);
	printf("test2 buffer:%s:", test);

}
