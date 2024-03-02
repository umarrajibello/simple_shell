#include "shell.h"

/**
 *exit_s - function that runs the exit builtin
 *@li : buffor for the line
 *@arg : args from the input
 *@env : enviroment
 * Returns Void
 */

void exit_s(char **arg, char *li, char **env)
{
	free(arg);
	free(li);
	(void)env;
	exit(0);

}
