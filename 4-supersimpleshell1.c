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
	char *buffer = NULL, *token = NULL, **toks = NULL, *concat = NULL, *path = NULL, *env = "PATH", *command = NULL;
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
		toks = malloc(sizeof(char *) * 1024);
		if (!toks)
			return (0);
		token = strtok(buffer, " \n");
		for (k = 0; token; k++)
		{
			toks[k] = token;
			token = strtok(NULL, " \n");
		}

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
		{
			path = get_env(env);
			printf("PATH is: %s\n", path);
			printf("Tok cero es igual a: %s\n", toks[0]);
			toks[0] = attach_path(path, toks);
			printf("Fullpath is: %s\n", toks[0] );
			if (toks[0] == NULL)
			{
				perror("Error: ");
				return (-1);
			}
			fk = fork();
			if (fk == -1)
				return (-1);
			if (!fk)
			{
				execve(toks[0], toks, NULL);
			}
			else
			{
				free(toks;
				wait(&status);
			}
		}
	}
	return (0);
}
