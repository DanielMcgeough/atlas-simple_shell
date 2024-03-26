#include "main_shell.h"

int forkcecute(char **cmd_ln)
{
        pid_t pid;
        /* char *args[]= {"ls", "-l", "/tmp", NULL};*/
        char *envp[] = {NULL};

        /* Check for empty arg array */
        if (cmd_ln == NULL || cmd_ln[0] == NULL)
        {
                perror("forkcecute cmd_ln empty");
                return (-1);
        }

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
                if (execve(cmd_ln[0], cmd_ln, envp) == -1)
                {
                        perror("execve failed");
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
        return 0;
}