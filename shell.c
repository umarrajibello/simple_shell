#include "shell.h"
/**
 * main - function runs an infinite loop for shell unless you exit
 * Return: 0
 */

int main(void)
{
	char *input;
	char **cmd_vec;

	while (1)
	{
		prompt(); /* display prompt*/
		input = r_input(); /*store input as null terminated string*/
		if (input == NULL)
		{
			break; /*end of file*/
		}
		cmd_vec = tokenize_input(input);
		run_cmd(cmd_vec);
		free(input);
		free(cmd_vec);
	}
	return (0);
}
