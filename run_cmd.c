#include "shell.h"

/**
 * run_cmd - function that runs the command entered in propmt
 * @cmd: the command entered in the prompt
 *
 * Return: nothing
 */
void run_cmd(char *cmd)
{
	pid_t child_pid = fork();

	if (child_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		execve(cmd, cmd, NULL);
		perror("execve");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
}
