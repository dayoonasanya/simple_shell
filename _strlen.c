#include "shell.h"

/**
 * _str_length - strlen.
 * @string: string.
 *
 * Return: strlen.
 */
int _str_length(char *string)
{
	int len = 0;

	if (string == NULL)
		return (0);

	while (string[len++] != '\0')
	{
	}
	return (--len);
}
