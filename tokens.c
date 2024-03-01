#include "shell.h"

/**
 * tokenize_input - funtion that tokenize input
 * input: receive input
 * Return: NULL
 */

char tokenize_input(char *input)
{
	char param = NULL;
	char *token = strtok(input, "");
	int arg_count = 0;

	while (token != NULL)
	{
		param = realloc(param, (arg_count + 2) * sizeof(char *));
		if (param == NULL)
		{
			perror("realloc");
			exit(EXIT_FAILURE);
		}
		param[arg_count++] = token;
		token = strtok(NULL, "");
	}
	param[arg_count] = NULL;
	return (param);
}
