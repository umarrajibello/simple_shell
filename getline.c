#include "shell.h"

/**
 *gline - Get the line from user input
 *Return: lptr to buffer user input
 */

char *gline(void)
{
	int tmp;
	char *lptr = NULL;
	size_t n = 0;

	tmp = getline(&lptr, &n, stdin);
	if (tmp == EOF)
	{
		if (isatty(STDIN_FILENO))
		{
			write(1, "\n", 1);
		}
		exit(0);
	}
	return (lptr);
}
