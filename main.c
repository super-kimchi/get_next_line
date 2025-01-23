/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyungkim <kyungkim@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:26:46 by kyungkim          #+#    #+#             */
/*   Updated: 2025/01/22 23:50:56 by kyungkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int	file = open("test.txt", O_RDONLY);
	printf("fd: %i\n", file);
	char *test = get_next_line(file);
	printf("test1 buffer: %s", test);

	test = get_next_line(file);
	printf("test2 buffer: %s", test);

	test = get_next_line(file);
	printf("test3 buffer: %s", test);

	test = get_next_line(file);
	printf("test4 buffer: %s", test);

	test = get_next_line(file);
	printf("test5 buffer: %s", test);
}
