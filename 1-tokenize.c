#include "main_shell.h"

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
