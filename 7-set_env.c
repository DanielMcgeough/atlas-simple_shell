#include "main_shell.h"
extern char **environ;

void print_environment(void) {
	int i = 0;
	while (environ[i] != NULL) {
		printf("%s\n", environ[i]);
		i++;
		}
}
