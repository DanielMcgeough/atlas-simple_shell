#include "main_shell.h"

/**
* tokenize- tokenizes string with space delim
* @str_ct: int for string count
* @i: int for a loop through array
* @l: int for a loop cleanup loop if strdup fails
* @k: a long int for length of buffer
* @array: an array to contain tokens in the form of strings
* @portion: a portion of a string tokenized
* Return: returns a char
*/
char **tokenize(char *buffer, char *delimiter)
{
	int str_ct = 0, i = 0, l = 0;
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
			return (NULL);
		}

		portion = strtok(buffer, delimiter);
		while (portion != NULL)
		{
			array[i] = strdup(portion);
			if (array[i] == NULL)
			{
				perror("tokenize strdup array failure]");
				for (l = 0; l < i; l++)
					free(array[l]);
					free(array);
						return (NULL);
			}
			i++;
			portion = strtok(NULL, delimiter);
		}
		array[i] = NULL;
		return (array);
}
