#include "shell.h"
/**
 * main - function runs an infinite loop for shell unless you exit
 * Return: 0
 */

int main(void)
{
	char *input;
	char **param;

	while (1)
	{
		displayPrompt();
		input = receiveInput();
		if (input == NULL)
		{
			break; /*end of file*/
		}
		param = tokenizeInput(input);
		runCommand(param);
		free(input);
		free(param);
	}
	return (0);
}
