#include "main.h"

/*
 * main - splits a string and returns an array of each word of the string
 * @ac: argument count
 * @av: argument vector
 */

int main (int ac, char **av __attribute__((unused)))
{
	unsigned long int j,k;
	size_t ptr = 0;
	char *buffer, *token, **toks;

	j = getline (&buffer, &ptr, stdin);
	if (j == -1)
	{
		printf("Error\n");
		return (-1);
	}
	toks = malloc(sizeof(char *) * ac);
	token = strtok(buffer, " ");
	while (k = 0, token, k++)
	{
		toks[k] = strdup(token);
		token = strtok(NULL, " ");
	}
	return (0);
}
