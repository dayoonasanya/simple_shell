#include "shell.h"


/**
 * _strtok - strtok.
 * @line: line.
 * @delim: delimeter.
 *
 * Return: pointer.
*/

char *_strtok(char *line, char *delim)
{
	int i;
	static char *str;
	char *cpystr;

	if (line != NULL)
		str = line;
	for (; *str != '\0'; str++)
	{
		for (i = 0; delim[i] != '\0'; i++)
		{
			if (*str == delim[i])
			break;
		}
		if (delim[i] == '\0')
			break;
	}
	cpystr = str;
	if (*cpystr == '\0')
		return (NULL);
	for (; *str != '\0'; str++)
	{
		for (i = 0; delim[i] != '\0'; i++)
		{
			if (*str == delim[i])
			{
				*str = '\0';
				str++;
				return (cpystr);
			}
		}
	}
	return (cpystr);
}
