#include "main_shell.h"

/**
 * str_chr- locates a specified character in a string if it exists.
 *
 * @c: the character to be located.
 *
 * @s: the string to be scanned.
 *
 * Return: returns 1 (true) if found. 0 if not found.
 */

int str_chr(char *s, char c)
{
	int i = 0;

	while ((s[i] != c) && (s[i] != '\0'))
	{
		i++;
	}
	if (s[i] == c)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
