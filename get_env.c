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
			str = strtok(NULL, "=");
			free(buff);
			return (str);
		}
	}
}
void main(void)
{
	char *env = "PATH";

	printf("%s\n", get_env(env));
}
char * find_path(*str, stdin)
{
		strtok(str, "=");
		strcat(str, stdin);
		while (excve(str, stdin, NULL) == -1)
		{
			str = strtok(NULL, ":");
			strcat(str, stdin);
			excve(str, stdin, NULL);



