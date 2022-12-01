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
	char *buffer, *token, **toks, *concat, *path, *env = "PATH", *command;
	pid_t pid;
	int status, check1;
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

		check1 = stat(buff, &st);
		if (check1 == 0)
		{

		}

		checkar = toks[0][0];
		if ((checkar >= 65 && checkar <= 90) || (checkar >= 97 && checkar <= 122)) // ls
		{
			path = get_env(env);
			command = attach_path(path, toks[0]);
			if (command == NULL)
			{
				printf("Command not found");
				return (-1);
			}
			else // if command found
			{ // primero checkear si te pasan un path a un programa, si no es encontrado concatenar, si no es encontrado command not found
				fk = fork();
				if (fk == -1)
					return(-1);
				if(!fk)
				{
					execve(command, toks[0], NULL);
				}
				else
					wait(&status);

				free(toks);
			}
		}
		if else // /usr/bin/ls
		else // /usr/bin/lsa || lsa || #"$#
		attach_path(path, toks[0]);
		free(toks);
	}
	return (0);
}
