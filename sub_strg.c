#include "shell.h"

/**
 * sub_str - function that locates sub string
 * @x: input one parameter
 * @x2: input two parameter
 * Return: sub string
 */

char *sub_str(char *x, char *x2)
{
	for (; *x != '\0'; x++)
	{
		char *one = x;
		char *two = x2;

		while (*one == *two && *two != '\0')
		{
			one++;
			two++;
		}

		if (*two == '\0')
			return (x);
	}

	return (NULL);

}
