#include "main.h"

int main (__attribute__((unused)) int ac,__attribute__((unused)) char **av)
{
	struct stat st;
	size_t ptr = 0, buffsize = 1024;
	int i, stream, check, fk;
	char *buffer = NULL, *token = NULL, **token_array = NULL;

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
	}
}
