#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
extern char **environ;

char * get_env(char *name)
{
	int i;
	char *buff, *token, *str;
	
	buff = malloc(sizeof(char *) * 100);
	for (i = 0; environ[i]; i++)
	{
		str = strtok(environ[i], "=");
		if (strcmp(str, name) == 0)
		{
			return (strtok(NULL, "="));
		}
	}
}
void main(void)
{
	char *env = "PATH";

	printf("%s\n", get_env(env));
}
