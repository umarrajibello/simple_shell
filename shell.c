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
		prompt(); /* display prompt*/
		input = r_input(); /*store input as null terminated string*/
		if (input == NULL)
		{
			break; /*end of file*/
		}
		param = tokenizeInput(input);
		run_cmd(param);
		free(input);
		free(param);
	}
	return (0);
}
