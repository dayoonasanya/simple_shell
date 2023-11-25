#include "shell.h"

/**
 * _str_duplicate - strdup.
 * @string: string.
 *
 * Return: returns array.
 */
char *_str_duplicate(char *string)
{
	char *out_arr;
	int len, i;

	if (string == NULL)
		return (NULL);

	len = _str_length(string) + 1;

	out_arr = malloc(sizeof(char) * len);

	if (out_arr == NULL)
	{
		errno = ENOMEM;
		perror("Error");
		return (NULL);
	}
	for (i = 0; i < len ; i++)
	{
		out_arr[i] = string[i];
	}

	return (out_arr);
}
