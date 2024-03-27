#include "main_shell.h"

/*
 * _memset- re-sets every char in a string to \0.
 *
 * @str: pointer to the char string to be set.
 *
 * Return: a pointer to the string.
 */

char *_memset(char *str)
{
	int i = 0, len;

	len = strlen(str);
	while (i < len)
		str[i] = '\0';
	return (str);
}
