#include "shell.h"
/**
 *b - Will check to see whether we are dealing with a builtin or not
 *@check: Figures out what to execute
 *@arg: Arguments passed from cmdline broken up
 *Return: 1 if user entered a path/builtin, 2 if user entered a binary
 */
int b(char *check, char **arg)
{
	int i = 0;

	if (builtins_ch(arg) == 1)
		return (1);
	while (check[i] != '\0')
	{
		if (check[i] == '/')
			return (1);
		i++;
	}
	return (2);
}
