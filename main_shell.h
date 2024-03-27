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
void *_memset(void *mem, int val, size_t bytes);
char *_strdup(char *str);
char *get_env(const char *name);

#endif
