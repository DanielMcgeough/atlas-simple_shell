#include "main_shell.h"

int main ()
{
	char *buffer;
	size_t buffsize = 4095;

	buffer = (char *)malloc(sizeof(char) * buffsize);
	if (buffer == NULL)
		return (-1);

	while (1)
	{
	/*display a prompt*/
	printf("$ ");

	/*The prompt is displayed again each time a command has been executed.*/
	printf("$ ");
	/*The command lines are made only of one word. */
	No arguments will be passed to programs.
	
	/*If an executable cannot be found, print an error message and display the prompt again.*/
	/*Handle errors.*/

	/*You have to handle the "end of file" condition (Ctrl+D) */

	}
}
