#include "main_shell.h"

/*
 * free_array- liberates memory for dynamically allocated arrays of strings.
 *
 * @i: an integer used to iterate through the array.
 *
 * Return: nothing.
 */

void free_array(char **array)
{
	int i = 0;

	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
}
