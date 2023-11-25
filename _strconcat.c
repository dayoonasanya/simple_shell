#include "shell.h"

void _str_reverse(char *string);
char *_str_concat(char *string1, char *string2);

/**
 * _str_reverse - strrev.
 * @string: string.
 *
 * Return: void.
 */
void _str_reverse(char *string)
{

	int i = 0, len = _str_length(string) - 1;
	char hold;

	while (i < len)
	{
		hold = string[i];
		string[i++] = string[len];
		string[len--] = hold;
	}
}

/**
 * _str_concat - strconcat.
 * @string1: s1.
 * @string2: s2.
 *
 * Return: array.
 */
char *_str_concat(char *string1, char *string2)
{
	char *out_arr;
	int len1 = 0, len2 = 0;

	if (string1 == NULL)
		string1 = "";
	len1 = _str_length(string1);

	if (string2 == NULL)
		string2 = "";
	len2 = _str_length(string2);

	out_arr = malloc(sizeof(char) * (len1 + len2 + 1));
	if (out_arr == NULL)
	{
		errno = ENOMEM;
		perror("Error");
		return (NULL);
	}

	for (len1 = 0; string1[len1] != '\0'; len1++)
		out_arr[len1] = string1[len1];
	free(string1);

	for (len2 = 0; string2[len2] != '\0'; len2++)
	{
		out_arr[len1] = string2[len2];
		len1++;
	}

	out_arr[len1] = '\0';
	return (out_arr);
}
