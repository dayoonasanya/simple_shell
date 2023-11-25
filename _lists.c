#include "shell.h"

int _builtins_list(data_of_program *data);

/**
 * _builtins_list - list.
 * @data: data.
 *
 * Return: 0 on success.
 **/

int _builtins_list(data_of_program *data)
{
	int iterator;
	builtins options[] = {
		{"exit", _builtin_exit},
		{"help", _builtin_help},
		{"cd", _builtin_cd},
		{"alias", _builtin_alias},
		{"env", _builtin_env},
		{"setenv", _builtin_set_env},
		{"unsetenv", _builtin_unset_env},
		{NULL, NULL}
	};

	for (iterator = 0; options[iterator].builtin != NULL; iterator++)
	{
		if (_str_compare(options[iterator].builtin, data->command_name, 0))
		{
			return (options[iterator].function(data));
		}
	}
	return (-1);
}
