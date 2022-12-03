#include "main.h"

int main (__attribute__((unused)) int ac,__attribute__((unused)) char **av)
{
	struct stat st;
	size_t ptr = 0, buffsize = 1024;
	int i, stream, check, fk;
	char *buffer = NULL, *token = NULL, **token_array = NULL, *path = NULL;

	while (1)
	{		/* Prompt display */
		printf("$ ");
		stream = getline(&buffer, &ptr, stdin);
		if (stream == -1)
		{
			perror("Error: ");
			return (-1);
		}
			/* Argument tokenisation */
		token_array = malloc(buffsize);
		if (!token_array)
		{
			perror("Error: ");
			return (-1);
		}
		token = strtok(buffer, " \n");
		for (i = 0; token; i++)
		{
			token_array[i] = token;
			token = strtok(NULL, " \n");
		}
			/* Command execution */
		if (strcmp(token_array[0], "exit") == 0)
			exit(0);

		check = stat(token_array[0], &st);
		if (check == 0) // if given full path
		{
			fk =  fork();
			if (fk < 0)
			{
				perror("Error: ");
				return (-1);
			}
			if (fk == 0) // child process
			{
				execve(token_array[0], token_array, NULL);
			}
			else // parent process
			{
				wait(NULL);
			}
		}
		else // if full path not given
		{
			path = get_env("PATH");
			printf("Path is: %s\n", path);
			token_array[0] = attach_path(path, token_array);
			if (token_array[0] == NULL) // if command is not found
			{
				return(-1);
			}
			else // if command is found
			{
				fk = fork();
				if (fk < 0)
				{
					return (-1);
				}
				if (fk == 0) // child process
				{
					execve(token_array[0], token_array, NULL);
				}
				else
				{
					wait(NULL);
					free(token_array);
				}
			}
		}
	}
}

char *get_env(char *name)
{
	size_t buffsize = 1024;
	int i;
	char *token = NULL, *token_cpy = NULL, *buff = NULL;

	if (!environ)
		return (NULL);
	for (i = 0; environ[i]; i++)
	{	
		buff = strdup(environ[i]);
		token = strtok(buff, "=");

		if (strcmp(token, name) == 0)
		{
			token = strtok(NULL, "=");
			if (token)
			{
				token_cpy = strdup(token);
				free(buff);
				return (token_cpy);
			}
		}
		free(buff);
	}
}

char *attach_path(char *str, char **input)
{
	struct stat st;
	size_t buffsize = 1024;
	int i;
	char *full_path = NULL, *token = NULL, *str_cpy;

	str_cpy = str;
	token = strtok(str_cpy, ":");
	while (token)
	{
		full_path = malloc(buffsize);
		strcpy(full_path, token);
		strcat(full_path, "/");
		strcat(full_path, input[0]);
		if (stat(full_path, &st) == 0)
		{
			return(full_path);
		}
		free(full_path);
		token = strtok(NULL, ":");

	}
	return (NULL);
}
