#include "shell.h"

int _printe(char *string);
int _print(char *string);

/**
 * _printe - print-e
 * @string: string.
 *
 * Return: return bytes.
 */
int _printe(char *string)
{
	return (write(STDERR_FILENO, string, _str_length(string)));
}

/**
 * _print - print.
 * @string: string.
 *
 * Return: return bytes.
 */
int _print(char *string)
{
	return (write(STDOUT_FILENO, string, _str_length(string)));
}
