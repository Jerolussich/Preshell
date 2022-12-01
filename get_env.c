#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
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
void * attach_path(char *str, char const *input)
{
	int fk = 0;
	int status;
	struct stat st;

		strtok(str, ":");
		strcat(str, "/");
		strcat(str, input);
		fk = fork();
		if (!fk)
		{
			while (stats(str, input, NULL) == -1 && str)
			{
				str = strtok(NULL, ":");
				strcat(str, "/");
				strcat(str, input);
			}
		}
		else if(wait(&status) < 0)
			printf("command not found");
}
void main(void)
{
        char *env = "PATH";
        char *input = "ls", *output;

         output = get_env(env);
         attach_path(output, input);
}


