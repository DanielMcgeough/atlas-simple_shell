#include "main_shell.h"

/**
 * get_xpath - searches the directories in the environment path
 * for a filename that matches a specified string.
 *
 * @command: the char string containing the filename
 * to be searched for.
 *
 * Return: if a match is found, returns a pointer to a string
 * containing the executable path for the command. NULL on failure.
 */

char *get_xpath(char *command)
{
	char *path;
	char *dir;
	char *xpath = NULL;

	path = get_env("PATH");
	dir = strtok(path, ":");

	while (dir != NULL)
	{
		dir = strtok(NULL, ":");
		sprintf(xpath, "%s/%s",dir, command);
		if (access(xpath, X_OK))
			return (xpath);
	}
	return (NULL);
}

/**
* forkcecute- to fork and execute a process
* @cmd_ln: the command line passed in to the shell
* Return: returns an int
*/
int forkcecute(char **cmd_ln)
{
	char *xpath;
	pid_t pid;
	/* char *args[]= {"ls", "-l", "/tmp", NULL};*/
	char *envp[] = {NULL};

	/* Check for empty arg array */
	if (cmd_ln == NULL || cmd_ln[0] == NULL)
	{
		free_array(cmd_ln);
		return (-1);
	}
	xpath = get_xpath(cmd_ln[0]);
	/*INSERT REALLOC FUNC HERE*/
	pid = fork();
	if (pid == -1)
	{
		perror("fork failed");
		return (-1);
	}
	else if (pid == 0)
	{
		/* Child process */
		/*printf("Child process %d executing %s\n", getpid(),cmd_ln[0]);*/
		if (execve(xpath, cmd_ln, envp) == -1)
		{
			free_array(cmd_ln);
			/*perror("execve failed");*/
			exit(EXIT_FAILURE);
		}
		/* exit(EXIT_SUCCESS); */
	}
	else
	{
		/* Parent process */
		/* Wait for the child to exit */
		wait(NULL);
		/*printf("Child process %d exited\n", pid);*/
	}
	free_array(cmd_ln);
	return (0);
}
