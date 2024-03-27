#ifndef MAIN_SHELL_H
#define MAIN_SHELL_H

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

char **tokenize(char *buffer, char *delimiter);
int forkcecute(char **cmd_ln);
void free_array(char **array);
char *_memset(char *str);

#endif
