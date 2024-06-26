#include "main_shell.h"

/**
 * get_xpath - searches the directories in the environment path
 * for a filename that matches a specified string.
 *
 * @command: the char string containing the filename
 * to be searched for.
 *
 * @env: vector of environment variables.
 *
 * Return: if a match is found, returns a pointer to a string
 * containing the executable path for the command. NULL on failure.
 */
char *get_xpath(char *command, char **env)
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
	path = get_env("PATH", env);
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
		sprintf(xpath, "%s/%s", dir, command);
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
* @env: vector of environment variables.
* Return: returns an int
*/
int forkcecute(char **cmd_ln, char **env)
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
		return (0);
	}
	xpath = get_xpath(cmd_ln[0], env);
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
		/* Child process */
		execve(xpath, cmd_ln, envp);
	else
	{
		/* Parent process */
		wait(&status);
		status = WEXITSTATUS(status);
	}
	free(xpath);
	free_array(cmd_ln);
	return (status);
}
