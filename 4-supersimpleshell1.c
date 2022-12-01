#include "main.h"

/*
 * main - run commands with their full path
 * @ac: argument count
 * @av: argument vector
 */

int main (int ac, char **av)
{
	unsigned long int j,k,fk;
	size_t ptr = 0;
	char *buffer, *token, **toks, *concat, *path, *env = "PATH", *command;
	pid_t pid;
	int status, check1;
	char array[10];
	struct stat st;

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

		check1 = stat(toks[0], &st);
		if (check1 == 0)//if given full path
		{
			fk = fork();
			if (fk == -1)
				return (-1);
			if (!fk)
				execve(toks[0], toks, NULL);
			else
			{
				wait(&status);
				free(toks);
			}
		}
		else// if full path not given
		{	printf("test");
			path = get_env(env);
			printf("%s test1", path);
			command = attach_path(path, toks[0]);
			printf("%s test2", command);
			if (command == NULL)
			{
				perror("Error: ");
				return (-1);
			}
			printf("test3");
			fk = fork();
			if (fk == -1)
				return (-1);
			if (!fk)
				execve(command, toks, NULL);
			else
			{
				wait(&status);
				free(toks);
			}
		}
	}
	return (0);
}
