#include "main.h"

char *get_env(char *name)
{
	int i;
	char *buff = NULL, *token = NULL, *str = NULL;
	size_t buffsize = 1024;

	buff = malloc(buffsize);
	for (i = 0; environ[i]; i++)
	{
		str = strtok(environ[i], "=");
		if (strcmp(str, name) == 0)
		{
			str = strtok(NULL, "=");
			free(buff);
			return (str);
		}
	}
}
char *attach_path(char *str, char **input)
{
	int fk = 0, status, found, len = 0, i = 0, j = 0;
	struct stat st;
	char *buff = NULL, *token = NULL, **direction = NULL;
	size_t buffsize = 1024;

	direction = malloc(buffsize);
	if (!direction)
		return (NULL);
	token = strtok(str, ":");
	for (i = 0; token; i++)
	{
		direction[i] = token;
		token = strtok(NULL, ":");
	}
	direction[i] = token;

	while (direction)
	{
		char *input_cpy = input[0];
		printf("Input copy: %s\n", input_cpy);
		char *str_path = malloc(buffsize);
		printf("Allocated str_path memory\n");
		strcpy(str_path, direction[j]);
		printf("Copy of direction[i]: %s\n", str_path);
		strcat(str_path, "/");
		printf("Added XX: %s\n", str_path);
		strcat(str_path, input_cpy);
		printf("Added ls: %s\n", str_path);
		if (stat(str_path, &st) == 0)
		{
			free_grid(direction, 1024);
			return (str_path);
		}
		j++;
		free(str_path);
	}
	free_grid(direction, 1024);
	return(NULL);
}

/**
 * free_grid - Frees a 2 dimensional grid
 * @grid: Grid to be freed
 * @height: Height of the grid
*/

void free_grid(char **grid, int height)
{
	int i;

	if (!grid)
	{
		for (i = 0; i < height; i++)
		{
			free(grid[i]);
		}
		free(grid);
	}
}
