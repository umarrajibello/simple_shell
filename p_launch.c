#include "shell.h"
/**
 *p_launch - Forks and launches the Program
 *@arg : arguments
 *Return: 1 on success
 */
int p_launch(char **arg)
{
	pid_t p_id, w_id;
	int stts;

	p_id = fork();
	if (p_id == 0)
	{
		if (execve(arg[0], arg, NULL) == -1)
		{
			perror("Failed\n");
			exit(0);

		}
	}
	else if (p_id < 0)
	{
		perror("Failed to use Fork\n");
		exit(0);
	}
	else
	{
		do {
			w_id = waitpid(p_id, &stts, WUNTRACED);
		} while (!WIFEXITED(stts) && WIFSIGNALED(stts));
	}
	(void)w_id;
	return (1);
}
