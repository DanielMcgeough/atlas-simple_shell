#include "main_shell.h"

/*
*print environment- prints the environment.
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
