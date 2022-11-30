#include "main.h"

/*
 * main - print all arguments
 * @ac: argument count
 * @av: argument vector
 */

int main (int ac __attribute__((unused)), char **av __attribute__((unused)))
{
	unsigned long int j;
	size_t ptr = 0;
	char *buffer;

	printf("$ ");

	while (1)	
	{
		j = getline (&buffer, &ptr, stdin);
		if (j == -1)
		{
			printf("Error\n");
			return (-1);
		}

		printf("%s", buffer);
		printf("$ ");
	}
	return (0);
}
