#include "main.h"
#include <stdio.h>

/*
 * main - print all arguments
 * @ac: argument count
 * @av: argument vector
 */

int main(int ac __attribute__((unused)), char **av)
{
	int i;

	for (i = 1; av[i]; i++)
		printf("%s ", av[i]);
	printf("\n");
	return (0);
}
