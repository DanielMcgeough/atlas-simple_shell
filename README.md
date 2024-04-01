# Simple Shell

## NAME
`simple_shell` - A custom implementation of a shell.

## SYNOPSIS
<stdio.h>
<stddef.h>
<stdlib.h>
<string.h>
<unistd.h>
<sys/types.h>
<sys/wait.h>


## DESCRIPTION
The Shell is designed to perform operations both in interactive mode and non interactive mode.In interactive mode the shell is designed to recieve commands input by the user and perform the specified option. For instance, if someone were to enter the "ls" command into the interactive mode portion of our shell, it would perform as expected and display a list of all files in the current directory. If one were to add flags to ls, once again it would perform as expected. In non interactive mode, our shell is designed to accept the environment variable full path, tokenize the PATH and perform the necessary operation.

The function is similar to the bash shell. The primary focus is on the following functions:

- `strtok` -  is a C function used to tokenize (split) a string into smaller substrings based on specified delimiters. It returns pointers to successive tokens found in the string until no more tokens are found, after which it returns NULL.
- `execve` - is a C function used to execute a program. It replaces the current process image with a new process image loaded from the specified executable file, along with its arguments and environment variables.
- `wait` - is a C function used to suspend the execution of the calling process until one of its child processes terminates or a signal is received. It returns the process ID of the terminated child process, or -1 if an error occurs.
- `getpid` - is a C function used to retrieve the process ID (PID) of the calling process. It returns an integer representing the PID of the current process.

The list is not exhaustive and other functions were used.

## HOW TO COMPILE
The Shell is compiled through the use of the "gcc Wall Werror Wextra -pedantic -std=gnu89 *.c" command. From there, executing the compiled program will grant you entry into the shell where it awaits user input for specific commands or paths.

## EXAMPLES
The Shell is designed to perform operations both in interactive mode and non interactive mode.In interactive mode the shell is designed to recieve commands input by the user and perform the specified option. For instance, if someone were to enter the "ls" command into the interactive mode portion of our shell, it would perform as expected and display a list of all files in the current directory. If one were to add flags to ls, once again it would perform as expected. In non interactive mode, our shell is designed to accept the environment variable full path, tokenize the PATH and perform the necessary operation. ls returns the following:
command:- `ls` -
- `result` -  0-shell_main.c  2-forkcecute.c  4-_memset.c  6-env.c      AUTHORS    hsh           man_1_simple_shell
1-tokenize.c    3-free_array.c  5-_strdup.c  7-set_env.c  README.md  main_shell.h
command: 
## HOW TO USE YOUR SHELL
The best method to use our shell is the same as the normal method to use any other shell. We have tried to make it as seamless as possible.

## AUTHOR
Dany McGeough and Nathan Rhys
