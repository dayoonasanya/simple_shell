#include "shell.h"

int _count_characters(char *string, char *character);
void _long_to_string(long number, char *string, int base);

/**
 * _count_characters - counter for char.
 * @string: string.
 * @character: char.
 *
 * Return: 0 or int.
 */

int _count_characters(char *string, char *character)
{
	int i = 0, counter = 0;

	for (; string[i]; i++)
	{
		if (string[i] == character[0])
			counter++;
	}
	return (counter);
}

/**
 * _long_to_string - string from long.
 * @number: num.
 * @string: string.
 * @base: base.
 *
 * Return: return nothing.
 */
void _long_to_string(long number, char *string, int base)
{
	int index = 0, inNegative = 0;
	long cociente = number;
	char letters[] = {"0123456789abcdef"};

	if (cociente == 0)
		string[index++] = '0';

	if (string[0] == '-')
		inNegative = 1;

	while (cociente)
	{
		if (cociente < 0)
			string[index++] = letters[-(cociente % base)];
		else
			string[index++] = letters[cociente % base];
		cociente /= base;
	}
	if (inNegative)
		string[index++] = '-';

	string[index] = '\0';
	_str_reverse(string);
}
