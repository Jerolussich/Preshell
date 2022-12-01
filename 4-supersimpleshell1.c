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
	char *buffer, *token, **toks, *concat, *path, *env = "PATH";
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

		if (toks[0][0] != "/") // ls
		{
			path = get_env(env);
			attach_path(path, toks[0]);

		}
		if else // /usr/bin/ls
		else // /usr/bin/lsa || lsa || #"$#
		attach_path(path, toks[0]);
		free(toks);
	}
	return (0);
}
