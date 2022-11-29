#include "main.h"

/*
 * main - run commands with their full path
 * @ac: argument count
 * @av: argument vector
 */

int main (int ac, char **av __attribute__((unused)))
{
	unsigned long int j,k;
	size_t ptr = 0;
	char *buffer, *token, **toks;

	while (1)
	{
		printf("$ ");
		j = getline(&buffer, &ptr, stdin);
		if (j == -1)
		{
			printf("Error\n");
			return (-1);
		}
		toks = malloc(sizeof(char *) * ac);
		if (!toks)
			return (0);
		token = strtok(buffer, " ");
		for (k = 0; token; k++)
		{
			toks[k] = strdup(token);
			token = strtok(NULL, " ");
			printf("%s", toks[k]);
		}
		toks[k] = token;


	}
	return (0);
}
