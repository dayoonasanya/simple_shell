#include "shell.h"

int _check_logic_ops(char *array_commands[], int i, char array_operators[]);

/**
* _check_logic_ops - logical operators.
* @array_commands: array.
* @i: index.
* @array_operators: array.
*
* Return: return index.
*/

int _check_logic_ops(char *array_commands[], int i, char array_operators[])
{
	char *temp = NULL;
	int j;

	for (j = 0; array_commands[i] != NULL  && array_commands[i][j]; j++)
	{
		if (array_commands[i][j] == '&' && array_commands[i][j + 1] == '&')
		{
			temp = array_commands[i];
			array_commands[i][j] = '\0';
			array_commands[i] = _str_duplicate(array_commands[i]);
			array_commands[i + 1] = _str_duplicate(temp + j + 2);
			i++;
			array_operators[i] = '&';
			free(temp);
			j = 0;
		}
		if (array_commands[i][j] == '|' && array_commands[i][j + 1] == '|')
		{
			temp = array_commands[i];
			array_commands[i][j] = '\0';
			array_commands[i] = _str_duplicate(array_commands[i]);
			array_commands[i + 1] = _str_duplicate(temp + j + 2);
			i++;
			array_operators[i] = '|';
			free(temp);
			j = 0;
		}
	}
	return (i);
}
