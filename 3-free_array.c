#include "main_shell.h"

/**
 * free_array- liberates memory for dynamically allocated arrays of strings.
 *
 * @array: the array of strings to be freed.
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
