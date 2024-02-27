#include "shell.h"

/**
 * main -Entry point
 *
 * Return: 0 on success -1 otherwise
 */
int main(void);
int main(void)
{
	pid_t pid;
	size_t token_count, input_size = 0;
	char **tokens;
	char *input = NULL, *delim = " \n";

	while (1)
	{
		/* Print prompt */
		printf("$ ");
		fflush(stdout);
		/* Read input using getline */
		if (getline(&input, &input_size, stdin) == -1)
		{
			printf("\n");
			break;
		} /* Parse input */
		token_count = tokenize(input, delim);
		tokens = word_list(input, delim);
		if (token_count == 0)
			continue;  /* Empty input, prompt again */
		if (strcmp(tokens[0], "exit") == 0) /* Handle built-in */
			break;
		else if (strcmp(tokens[0], "cd") == 0)
		{
			if (token_count < 2)
				fprintf(stderr, "cd: missing argument\n");
			else
			{
				if (chdir(tokens[1]) != 0)
					perror("cd");
			}
			continue;
		}
		pid = fork(); /* Execusion start */
		if (pid == 0) /*Child process*/
		{
			execvp(tokens[0], tokens);
			perror("execvp");  /* execvp failed */
			exit(EXIT_FAILURE);
		}
		else if (pid < 0)
			perror("fork"); /*Error forking*/
		else
			wait(NULL);  /* Parent wait for child to complete */
	}
	free(input); /* Free memory allocated by getline */
	return (0);
}
