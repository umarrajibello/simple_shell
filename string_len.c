#include "shell.h"

/**
 * strr_len - a function that returns the length of a string
 * @s: char input parameter
 * Return: length of the input string
 */
int strr_len(char *s)
{
	int length = 0;

	while (*s != '\0')
	{
		length++;
		s++;
	}
	return (length);

}
