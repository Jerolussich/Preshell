#include "main.h"

/**
 * main - shell 
 * @ac: argument count
 * @av: argument vector
 * Return: return -1 if failed or command output
 */
int main (int ac, char **av)
{
	struct stat st;
	size_t ptr = 0, buffsize = 1024;
	int i, stream, check, fk;
	char *buffer = NULL, *token = NULL, **token_array = NULL, *path = NULL;

	while (1)
	{
		isatty(STDIN_FILENO) == 1 ? write(1, "$ ", 2) : 0;
			/* Prompt display */
		buffer = malloc(buffsize);
		if (!buffer)
			return (-1);
		stream = getline(&buffer, &ptr, stdin);
		if (stream == -1)
		{
			free(buffer);
			exit(0);
		}
			/* Argument tokenisation */
		token_array = malloc(buffsize);
		if (!token_array)
		{
			free(buffer);
			perror("Error: ");
			return (-1);
		}
		token = strtok(buffer, " 	\n");
		for (i = 0; token; i++)
		{
			token_array[i] = token;
			token = strtok(NULL, "        \n");
		}
		token_array[i] = NULL;

			/* Exit function */
		if (strcmp(token_array[0], "exit") == 0)
		{
			free_grid(token_array);
			free(buffer);
			exit(0);
		}
			/* Print env function */
		if (strcmp(token_array[0], "env") == 0)
			print_env();

			/* Command execution */
		check = stat(token_array[0], &st);
		if (check == 0) // if given full path
		{
			fk =  fork();
			if (fk < 0)
			{
				free_grid(token_array);
				printf("Free_grid worked properly");
				free(buffer);
				perror("Error: ");
				return (-1);
			}
			if (fk == 0) // child process
				execve(token_array[0], token_array, NULL);
			else // parent process
			{
				free_grid(token_array);
                                printf("Free_grid worked properly");
				wait(NULL);
			}
		}
		else if (check == -1) // if full path not given
		{
			path = get_env("PATH");
			token_array[0] = attach_path(path, token_array);
			free(path);
			check = stat(token_array[0], &st);
			if (check == 0)
			{
				fk =  fork();
				if (fk < 0)
				{
					free(buffer);
					perror("Error: ");
					return (-1);
				}
				if (fk == 0) // child process
					execve(token_array[0], token_array, NULL);
		
			}
			if (check == -1)
				perror("Error: ");	
			else // parent process
				wait(NULL);

			free(buffer);
		/*	free_grid(token_array); */
		}
	}
}

/**
 * get_env - search env por specific line
 * @name: word to look for in env
 * Return: return NULL if failed or pointer to path
 */
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
			free(buff);
		}
		free(buff);
	}
}
/**
 * attach_path - add corresponding path to command given
 * @str: string given with path
 * @input:input given in shell
 * Return: string with full path or NULL if failed
 */

char *attach_path(char *str, char **input)
{
	struct stat st;
	size_t buffsize = 1024;
	int i;
	char *full_path = NULL, *token = NULL, *str_cpy;

	str_cpy = strdup(str);
	token = strtok(str_cpy, ":");
	while (token)
	{
		full_path = malloc(buffsize);
		strcpy(full_path, token);
		strcat(full_path, "/");
		strcat(full_path, input[0]);
		if (stat(full_path, &st) == 0)
		{
			free(str_cpy);
			return(full_path);
		}
		free(full_path);
		token = strtok(NULL, ":");
	}
	free(str_cpy);
	return (NULL);
}
/**
 * print_env - print env content
 * Return: void
 */
void print_env()
{
	size_t buffsize = 1024;
	int i;
	char *token = NULL, *buff = NULL;

	if (!environ)
		return;

	for (i = 0; environ[i]; i++)
	{
		buff = strdup(environ[i]);
		printf("%s\n", buff);
	}
	free(buff);
	return;
}
