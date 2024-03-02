#include "shell.h"

/**
 *exe_prog - Executes builtin
 *@arg: Argument
 *@li: Line buffer
 *@env: Environment
 *@flow: Helps decide what code to run
 *Return: 1 if success
 */
int exe_prog(char **arg, char *li, char **env, int flow)
{
	int status;

	if (arg[0] == NULL)
		return (1);
	if (flow == 1)
	{
		if (c_builtin(arg, li, env) == 1)
			return (1);
	}
	status = p_launch(arg);
	return (status);

}
