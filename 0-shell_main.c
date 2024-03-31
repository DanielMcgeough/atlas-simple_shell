#include "main_shell.h"
#include <errno.h>

/**
* main- this is the function to setup inputs
* Return: returns an int
*/

int main(/*int ac, char **av, char **env*/)
{
	int status = 0;
	char *buffer;
	char **cmd_ln = NULL;
	size_t buffsize = 4095;
	ssize_t bytes_read;
	extern char **environ;

	buffer = (char *)malloc(sizeof(char) * buffsize);
		if (buffer == NULL)
			return (-1);

		while (1)
		{
			if (isatty(STDIN_FILENO))
				printf("$ ");
			bytes_read = getline(&buffer, &buffsize, stdin);
			if (bytes_read == -1)
			{
				free(buffer);
				break;
			}
			else if (bytes_read == 1)
				continue;
			buffer[bytes_read - 1] = '\0';

			if (strncmp(buffer, "exit", 4) == 0)
			{
				free(buffer);
				break;
			}
			if (strncmp(buffer, "env", 3) == 0)
			{
				print_environment(environ);
				free(buffer);
				break;
				/*continue;*/
			}
			cmd_ln = tokenize(buffer, " ");
			status = (forkcecute(cmd_ln));
			/*if (status != 0)
			{
				free(buffer);
				perror(NULL);
				printf("status %d\nerrno %d\n", status, errno);
				free_array(cmd_ln);
				fprintf(stderr, "%s: %d: %s: not found\n", av[0], ac, cmd_ln[0]);
				exit(127);
			}*/
		}
		return (status);
}
