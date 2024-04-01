#include "main_shell.h"

/**
*print_environment- prints the environment.
*@env: it stands for environment.
*Return: returns a void.
*/

void print_environment(char **env)
{
	int i = 0;

	while (env[i] != NULL)
	{
		printf("%s\n", env[i]);
		i++;
	}
}

/**
*get_env- gets path from environment
*@key: char to select value
*Return: returns a char
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
			return (environ[i] + length + 1);
		i++;
	}
	return (NULL);
}
