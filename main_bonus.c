#include <fcntl.h>
#include <stdio.h>
#include "get_next_line_bonus.h"

int	main(void)
{
	int	file;
	file = open("testfiles/test.txt", O_RDONLY);
	printf("fd: %i\n", file);
	char *test = get_next_line(3);
	printf("fd: %i test1: %s\n", file, test);

	file = open("testfiles/test1.txt", O_RDONLY);
	printf("fd: %i\n", file);
	test = get_next_line(4);
	printf("fd: %i test1: %s\n", file ,test);

	printf("fd: %i\n", file);
	test = get_next_line(3);
	printf("fd: %i test2: %s\n", file, test);
	printf("fd: %i\n", file);
	test = get_next_line(4);
	printf("fd: %i test2: %s\n", file, test);
	//printf("test3: %s", test);
	//test = get_next_line(file);
	//printf("test4: %s", test);

/*
	char *test = get_next_line(file);
	printf("fd: %i\n", file);
	printf("test buffer: %s\n", test);
	file = -1;
	test = get_next_line(file);
	printf("fd: %i\n", file);
	printf("test buffer: %s\n", test);

	file = open("testfiles/empty", O_RDONLY);

	printf("empty test\n");
	test = get_next_line(file);
	printf("fd: %i\n", file);
	printf("test buffer: %s\n", test);
	test = get_next_line(file);
	printf("fd: %i\n", file);
	printf("test buffer: %s\n", test);
	close(file);

	file = open("testfiles/41_no_nl", O_RDONLY);
	printf("41_no_nl test\n");
	test = get_next_line(file);
	printf("fd: %i\n", file);
	printf("test buffer: %s\n", test);
	test = get_next_line(file);
	printf("fd: %i\n", file);
	printf("test buffer: %s\n", test);
	close(file);

	file = open("testfiles/1char.txt", O_RDONLY);
	printf("1char test\n");
	test = get_next_line(file);
	printf("fd: %i\n", file);
	printf("test buffer: :%s:\n", test);
	test = get_next_line(file);
	printf("fd: %i\n", file);
	printf("test buffer: %s\n", test);
	*/
}
