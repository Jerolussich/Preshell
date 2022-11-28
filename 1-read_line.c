#include "main.h"

/*
 * main - print all arguments
 * @ac: argument count
 * @av: argument vector
 */

int main (int ac __attribute__((unused)), char **av)
{
	unsigned long int j, len;
	size_t *str = NULL, *ptr = NULL;

	printf("$\n");

	while (1)	
	{
		
		ptr = malloc (sizeof(size_t));
		if (ptr == NULL)
		{
			printf("test1");
			return (-1);
		}
		j = getline (av, ptr, stdin);
		if (j == -1)
		{
			printf("Error\n");
			return (-1);
		}
		if (j = 1)
			printf("$ ");
		else
			printf("%ln\n", ptr);
		free(ptr);
	}
	return (0);
}
