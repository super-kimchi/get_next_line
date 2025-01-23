/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyungkim <kyungkim@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:26:46 by kyungkim          #+#    #+#             */
/*   Updated: 2025/01/23 19:50:09 by kyungkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int	file;
	file = 1000;
	char *test = get_next_line(file);
	printf("fd: %i\n", file);
	printf("test buffer: %s\n", test);
	file = -1;
	test = get_next_line(file);
	printf("fd: %i\n", file);
	printf("test buffer: %s\n", test);

	file = open("empty", O_RDONLY);

	printf("empty test\n");
	test = get_next_line(file);
	printf("fd: %i\n", file);
	printf("test buffer: %s\n", test);
	test = get_next_line(file);
	printf("fd: %i\n", file);
	printf("test buffer: %s\n", test);
	close(file);

	file = open("41_no_nl", O_RDONLY);
	printf("41_no_nl test\n");
	test = get_next_line(file);
	printf("fd: %i\n", file);
	printf("test buffer: %s\n", test);
	test = get_next_line(file);
	printf("fd: %i\n", file);
	printf("test buffer: %s\n", test);
	close(file);

	file = open("1char.txt", O_RDONLY);
	printf("1char test\n");
	test = get_next_line(file);
	printf("fd: %i\n", file);
	printf("test buffer: :%s:\n", test);
	test = get_next_line(file);
	printf("fd: %i\n", file);
	printf("test buffer: %s\n", test);
	/*
	 *
	while (test)
	{
		printf("test buffer: %s", test);
		free(test);
		test = get_next_line(file);
	}
	printf("test buffer: %s", test);
	*/
	/*
	free(test);
	test = get_next_line(file);
	printf("test2 buffer: %s", test);

	free(test);
	test = get_next_line(file);
	printf("test3 buffer: %s", test);

	free(test);
	test = get_next_line(file);
	printf("test4 buffer: %s", test);
	free(test);
	*/
	 //test = get_next_line(file);
	//printf("test5 buffer: %s", test);
}
