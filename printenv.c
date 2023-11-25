#include "shell.h"

/**
 * _print_environ - print env.
 * @data: data.
 *
 * Return: return nothing.
 */

void _print_environ(data_of_program *data)
{
	int j;

	for (j = 0; data->env[j]; j++)
	{
		_print(data->env[j]);
		_print("\n");
	}
}
