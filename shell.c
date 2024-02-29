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
	ssize_t nread = 0;
	size_t input_size = 0;
	char *input = NULL;
	char **param = NULL;

	while (1)
	{
		/* Print prompt */
		printf("$ ");
		fflush(stdout);
		/* Read input using getline */
		nread = getline(&input, &input_size, stdin);
		if (nread == -1)
		{
			printf("\n");
			break;
		} /* Parse input */
		else
			input[nread - 1] = '\0'; /* replace \n*/
		param = malloc(sizeof(char *) * 2);
		if (param == NULL)
		{
			perror("malloc");
			exit(EXIT_FAILURE);
		}
		param[0] = input;
		param[1] = NULL;
		printf("param: %s\n", param[0]);
		printf("input: %s\n", input);
		pid = fork(); /* Execusion start */
		if (pid == 0) /*Child process*/
		{
			execve(param[0], param, NULL);
			perror("execvp");  /* execvp failed */
			exit(EXIT_FAILURE);
		}
		else if (pid < 0)
			perror("fork"); /*Error forking*/
		else
		{
			wait(NULL);  /* Parent wait for child to complete */
			free(param);
		}
		free(input);
	}
	return (0);
}
