#ifndef MAIN_SHELL_H
#define MAIN_SHELL_H

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

typedef struct envar_node
{
	char *key_val;
	struct envar_node *prev;
	struct envar_node *next;
} envar_node;

char **tokenize(char *buffer, char *delimiter);
int forkcecute(char **cmd_ln);
void free_array(char **array);
void *_memset(void *mem, int val, size_t bytes);
char *_strdup(char *str);
char *get_env(const char *name);
char *get_xpath(char *command);
int str_chr(char *s, char c);
void print_environment(char **env);
void built_ins(char *buffer, int status, char **env);

#endif
