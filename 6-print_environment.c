#include "main_shell.h"

/*
*print environment
*/
extern char **environ;

void print_environment(char **env)
{
	int i = 0;
	while (env[i] != NULL)
	{
		printf("%s\n", env[i]);
		i++;
	}
}
