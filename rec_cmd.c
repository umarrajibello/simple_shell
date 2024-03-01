#include "shell.h"
/**
 * receive_command - funct that receive command
 * Return: input command received
 */

char *rec_cmd(void)
{
	char *input = NULL;
	size_t input_size = 0;
	ssize_t nread = getline(&input, &input_size, stdin);

	if (nread <= 0)
	{
		if (nread == 0)
		{
			printf("\n");
			free(input);
			return (NULL);
		}
		perror("getline");
		exit(EXIT_FAILURE);
	}
	input[nread - 1] = '\0'; /* replace new line character with null terminator */
	return (input);
}
