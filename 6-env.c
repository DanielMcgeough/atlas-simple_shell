#include "main_shell.h"

envar_node *create_node(char *value)
{
	envar_node *new_node = (envar_node *)malloc(sizeof(envar_node));
	if (new_node == NULL)
	{
		return (NULL);
	}
	new_node->value = _strdup(value);
	if (new_node->value == NULL)
	{
		free(new_node);
		return (NULL);
	}
	new_node->prev = NULL;
	new_node->next = NULL;
	return (new_node);
}

envar_node *env_list(char *path)
{
	envar_node *head = NULL;
	envar_node *tail = NULL;
	envar_node *new_node;
	char *token;

	if (path != NULL)
	{
		token = strtok(path, ":");
		while (token != NULL)
		{
			new_node = create_node(token);
			if (head == NULL)
			{
				head = new_node;
				tail = new_node;
			}
			else
			{
				tail->next = new_node;
				new_node->prev = tail;
				tail = new_node;
			}
			token = strtok(NULL, ":");

		}
	}
	return (head);
}

char *get_env(const char *key)
{
	extern char **environ;
	int i = 0;
	size_t length;

	length = strlen(key);
	while (environ[i] != NULL)
	{
		if (strncmp(key, environ[i], length) == 0  && environ[i][length] == '=')
			return(environ[i] + length + 1);
		i++;
	}
	return(NULL);
}

void free_list(envar_node *head)
{
	envar_node *current = head;
	envar_node *next;

	while (current != NULL)
	{
		next = current->next;
		free(current->value);
		free(current);
		current = next;
	}
}

// Function to convert a doubly linked list to an array
char **listToArray(struct envar_node *head) {
    int count = 0;
    struct envar_node *current = head;

    // Count the number of nodes in the linked list
    while (current != NULL) {
        count++;
        current = current->next;
    }

    // Allocate memory for the array of strings
    char **array = (char **)malloc((count + 1) * sizeof(char *));
    if (array == NULL) {
        exit(EXIT_FAILURE);

    // Copy the data from the linked list to the array
    current = head;
    for (int i = 0; i < count; i++) {
        array[i] = _strdup(current->data);
        if (array[i] == NULL) {
            exit(EXIT_FAILURE);
        }
        current = current->next;
    }

    // Set the last element of the array to NULL to mark the end
    array[count] = NULL;

    return array;
}