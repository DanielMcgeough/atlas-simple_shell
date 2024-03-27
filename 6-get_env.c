#include "main_shell.h"
char *get_env(const char *name)
{
	int i = 0;
	size_t length;

	length = strlen(name);
	while (environ[i] != NULL)
	{
		if (strncmp(name, environ[i], length) == 0  && environ[i][length] == '=')
			return(environ[i] + length + 1);
		i++;
	}
	return(NULL);
}