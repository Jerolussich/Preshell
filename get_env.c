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
char * attach_path(char *str, char const *input)
{
	int fk = 0, status, found;
	struct stat st;
	char * buff;

		strtok(str, ":");
		strcat(buff, str);
		strcat(buff, "/");
		strcat(buff, input);
		while (stat(buff, &st) == -1)
		{
			found = stat(buff, &st);
			str = strtok(NULL, ":");
				if (!str)
					break;
			buff = NULL;
			strcat(buff, str);
			strcat(buff, "/");
			strcat(buff, input);
		}
		if (found == 0)
		{
			return (buff);
		}
		else
		{
			return("Command not found");
		}

}
void main(void)
{
        char *env = "PATH";
        char *input = "ls", *output;

         output = get_env(env);
         attach_path(output, input);
}


