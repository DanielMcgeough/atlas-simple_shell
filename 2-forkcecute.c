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
	char *xpath;
	char *path_copy;

	if (str_chr(command, '/') && !access(command, X_OK))
	{
		xpath = _strdup(command);
		if (xpath == NULL)
			return (NULL);
		return (xpath);
	}
		
	path = get_env("PATH");
	if (path == NULL)
		return (NULL);
	path_copy = _strdup(path);
	dir = strtok(path_copy, ":");

	while (dir != NULL)
	{
		xpath = malloc(strlen(dir) + strlen(command) + 2);
		if (xpath == NULL)
		{
			free(path_copy);
			return (NULL);
		}
		sprintf(xpath, "%s/%s",dir, command);
		if (!access(xpath, X_OK))
		{
			free(path_copy);
			return (xpath);
		}
		dir = strtok(NULL, ":");
		free(xpath);
	}
	free(path_copy);
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
	int status;
	/* char *args[]= {"ls", "-l", "/tmp", NULL};*/
	char *envp[] = {NULL};

	/* Check for empty arg array */
	if (cmd_ln == NULL || cmd_ln[0] == NULL)
	{
		free_array(cmd_ln);
		return (-1);
	}
	xpath = get_xpath(cmd_ln[0]);
	if (xpath == NULL)
	{
		free(xpath);
		return (-1);
	}
	pid = fork();
	if (pid == -1)
	{
		free(xpath);
		free_array(cmd_ln);
		perror("fork failed");
		return (-1);
	}
	else if (pid == 0)
	{
		/* Child process */
		/*printf("Child process %d executing %s\n", getpid(),cmd_ln[0]);*/
		if (execve(xpath, cmd_ln, envp) == -1)
		{
			free(xpath);
			free_array(cmd_ln);
			/*perror("execve failed");*/
			exit(2);
		}
		/* exit(EXIT_SUCCESS); */
	}
	else
	{
		/* Parent process */
		/* Wait for the child to exit */
		wait(&status);
		if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
			exit(WEXITSTATUS(status));
		/*printf("Child process %d exited\n", pid);*/
	}
	free(xpath);
	free_array(cmd_ln);
	return (0);
}
