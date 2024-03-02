#include "shell.h"

/**
 *env_s - Shell enviroment
 *@arg: args from input
 *@li: line
 *@env: Enviroment
 */

void env_s(char **arg, char *li, char **env)
{
	int s, i = 0;

	while (env[i] != NULL)
	{
		s = strr_len(env[i]);
		write(1, env[i], s);
		write(1, "\n", 1);
		i++;
	}
	(void) arg;
	(void) li;

}
