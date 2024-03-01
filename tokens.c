#include "shell.h"

/**
 * tokenize_input - funtion that tokenize input
 * @input: input string
 * Return: array of tokens
 */

char **tokenize_input(char *input)
{
	char **cmd_vec = NULL;

	cmd_vec = malloc(sizeof(char *) * 2);
	if (cmd_vec == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	cmd_vec[0] = input;
	cmd_vec[1] = NULL;
	return (cmd_vec);
}
