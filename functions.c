#include "main.h"

void type_prompt()
{
	int i = 0;
	for (int i = 0; i < 50; i++)
		printf("\n");
}

void enviro_find(char *name)
{
	int i,str;

	buff = strdup(environ);
	token = strtok(buff, "=");

	for (i = 0; token; i++)
	{
		str = strcmp(token, name);
		if (!str)
			return (token);
		token = strtok(NULL, "=");
		if (!token)
			return(NULL);
	}




	
