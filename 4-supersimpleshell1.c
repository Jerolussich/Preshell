#include "main.h"

/*
 * main - run commands with their full path
 * @ac: argument count
 * @av: argument vector
 */

int main (int ac, char **av __attribute__((unused)))
{
	unsigned long int j,k,fk;
	size_t ptr = 0;
	char *buffer, *token, **toks, *concat, *path = "/bin/";
	pid_t pid;
	int status;
	char array[10];


	type_prompt();
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
		token = strtok(buffer, " \n");
		for (k = 0; token; k++)
		{
			toks[k] = strdup(token);
			token = strtok(NULL, " \n");
		}
		toks[k] = token;
		fk = fork();
		if (fk == -1)
			printf("fork error");
		
		strcpy(array, path);
		strcat(array, toks[0]);
		if (!fk)
		{
			if (execve(array, toks, NULL) == -1)
				printf("pid is null");
		}
		else
		{
			wait(&status);
			free(toks);
		}
	}
	return (0);
}
