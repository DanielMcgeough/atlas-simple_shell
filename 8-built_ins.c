#include "main_shell.h"

/**
*built_ins- checks for matches to build in funcs.
*@buffer: string that has been filled in main
*@status: Int to represent current process status.
*@env: vector of environment.
*Returns: returns a void.
*/
void built_ins(char *buffer, int status, char **env)
{
	if (strncmp(buffer, "exit", 4) == 0)
		{
		free(buffer);
		exit(status);
		}
	if (strncmp(buffer, "env", 3) == 0)
		{
		print_environment(env);
		free(buffer);
		break;
		}
}
