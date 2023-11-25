#include "shell.h"


/**
 * _builtin_exit - exit.
 * @data: data.
 *
 * Return: 0 on success.
 */

int _builtin_exit(data_of_program *data)
{
	int i;

	if (data->tokens[1] != NULL)
	{
		for (i = 0; data->tokens[1][i]; i++)
			if ((data->tokens[1][i] < '0' || data->tokens[1][i] > '9')
				&& data->tokens[1][i] != '+')
			{
				errno = 2;
				return (2);
			}
		errno = _atoi(data->tokens[1]);
	}
	_free_all_data(data);
	exit(errno);
}
