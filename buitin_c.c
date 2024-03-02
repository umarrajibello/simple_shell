#include "shell.h"

/**
 *c_builtin - Checks for Builtin commands
 *@arg: Arguments Captured from the user
 *@li: line buffer
 *@env: Enviroment
 *Return: 1 if exists else : 0
 */

int c_builtin(char **arg, char *li, char **env)
{
	builtin_list list[] = {
		{"exit", exit_s},
		{"env", env_s},
		{NULL, NULL}
	};
	int i;

	for (i = 0; list[i].arg != NULL; i++)
	{
		if (_str_compare(list[i].arg, arg[0]) == 0)
		{
			list[i].builtin(arg, li, env);
			return (1);
		}
	}
	return (0);
}

/**
 * builtins_ch - Checks for builtins
 * @arg: Arguments passed from prompt
 * Return: 1 if builtins exist, 0 if they don't
 */

int builtins_ch(char **arg)
{
	int i;
	builtin_list list[] = {
		{"exit", exit_s},
		{"env", env_s},
		{NULL, NULL}
	};

	for (i = 0; list[i].arg != NULL; i++)
	{
		if (_str_compare(list[i].arg, arg[0]) == 0)
			return (1);
	}
	return (0);

}
