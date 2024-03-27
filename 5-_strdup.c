#include "main_shell.h"

/**
 * _strdup- copies a string into sufficiently allocated memory and
 * returns a pointer to that space in memory.
 *
 * @str: the string to be copied into memory.
 *
 * Return: if adequate space in memory, returns pointer s. Else returns NULL.
 */

char *_strdup(char *str)
{
	int i, l;
	char *s;

	if (str == (NULL))
	{
		return (NULL);
	}

	l  = strlen(str);
	s = malloc(sizeof(char) * l + 1);
	if (s == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < l; i++)
	{
		s[i] = str[i];
	}
	s[i++] = '\0';
	return (s);
}
