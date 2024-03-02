#include "shell.h"

/**
 * get_env - gets enviroment of input
 *@env: inputs
 * Return: env without =
 */

char *get_env(char *env)
{
	int i = 0, n = 0;
	char *temp, *res;

	while (environ[i] != NULL)
	{
		if (_str_compare(environ[i], env) == 0)
			temp = environ[i];
		i++;
	}

	while (temp[n] != '\0')
	{
		if (_str_compare(temp, env) == 0)
			res = sub_str(temp, "/");
		n++;
	}
	return (res);
}
