#include "shell.h"

/**
 * run_cmd - function that runs the command
 * @cmd_vec: array of tokens containing command and args
 *
 * Return: nothing
 */
void run_cmd(char **cmd_vec)
{
	pid_t child_pid = fork();
	int status;

	if (child_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		execve(cmd_vec[0], cmd_vec, NULL);
		perror("execve");
		exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(child_pid, &status, 0);
		if (!WIFEXITED(status) || WEXITSTATUS(status) != 0)
			perror("cmd_vec[0]");
	}
}
