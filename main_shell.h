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
envar_node *create_node(char *value);
envar_node *env_list(char *path);
char *get_env(const char *key);
void free_list(envar_node *head);
char **listToArray(struct envar_node *head);

#endif
