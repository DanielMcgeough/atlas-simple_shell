#include "main_shell.h"

/**
* tokenize- tokenizes string with space delim
* @buffer: container for the string
* @delimiter: a way to separate tokens.
* Return: returns a char
*/
char **tokenize(char *buffer, char *delimiter)
{
	int str_ct = 0, i = 0;
	unsigned long int k;
	char **array = NULL;
	char *portion;

	for (k = 0; k < strlen(buffer); k++)
	{
		if (buffer[k] == ' ')
		str_ct++;
	}
	str_ct++;

	array = (char **)malloc(sizeof(char *) * (str_ct + 1));
		if (array == NULL)
		{
			perror("tokenize malloc array failure");
			_memset(buffer, '\0', 4095);
			return (NULL);
		}

		portion = strtok(buffer, delimiter);
		while (portion != NULL)
		{
			array[i] = strdup(portion);
			if (array[i] == NULL)
			{
				perror("tokenize strdup array failure]");
				free_array(array);
				_memset(buffer, '\0', 4095);
				return (NULL);
			}
			i++;
			portion = strtok(NULL, delimiter);
		}
		array[i] = NULL;
		_memset(buffer, '\0', 4095);
		return (array);
}
