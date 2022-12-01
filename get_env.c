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
char *attach_path(char *str, char const *input)
{
	int fk = 0, status, found, len = 0;
	struct stat st;
	char *buff = NULL, *token = NULL, *path = NULL;

	/* strtok(str, ":");
	buff = malloc(buffsize);
	strcpy(buff, str);
	strcat(buff, "/");
	strcat(buff, input); */

	buff = strdup(str);
	token = strtok(buff, ":");
	while (token)
	{
		path = malloc(sizeof(char) * 1024);
		strcpy(path, token);
		strcat(path, "/");
		strcat(path, input);
		printf("Command to execute: %s\n", path);
		if (stat(path, &st) == 0)
		{
			free(buff);
			free(path);
			return (path);
		}
		free (path);
		token = NULL;
		token = strtok(NULL, ":");

	}
	free(buff);
	return(NULL);
}
