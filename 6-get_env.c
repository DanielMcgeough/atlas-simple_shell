#include "main_shell.h"

/**
* get_env- gets the environment variable
* @name: the name is the var for strings
* Return: returns a char
*/

char *get_env(const char *key)
{
	extern char **environ;
	int i = 0;
	size_t length;

	length = strlen(key);
	while (environ[i] != NULL)
	{
		if (strncmp(key, environ[i], length) == 0  && environ[i][length] == '=')
		{
			printf("%s\n", environ[i]);
			return(environ[i] + length + 1);
		}
		i++;
	}
	return(NULL);
}
