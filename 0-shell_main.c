#include "main_shell.h"

/**
* main- this is the function to setup inputs
* Return: returns an int
*/

int main(void)
{
	char *buffer;
	char **cmd_ln = NULL;
	size_t buffsize = 4095;
	ssize_t bytes_read;

	buffer = (char *)malloc(sizeof(char) * buffsize);
		if (buffer == NULL)
			return (-1);

		while (1)
		{
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
			cmd_ln = tokenize(buffer, " ");
			forkcecute(cmd_ln);
		}
		return (0);
}
