#include "shell.h"

int _builtin_env(data_of_program *data);
int _builtin_set_env(data_of_program *data);


/**
 * _builtin_env - env.
 * @data: data.
 *
 * Return: 0 on success.
 */
int _builtin_env(data_of_program *data)
{
	int i;
	char cpname[50] = {'\0'};
	char *var_copy = NULL;

	if (data->tokens[1] == NULL)
		_print_environ(data);
	else
	{
		for (i = 0; data->tokens[1][i]; i++)
		{
			if (data->tokens[1][i] == '=')
			{
				var_copy = _str_duplicate(_env_get_key(cpname, data));
				if (var_copy != NULL)
					_env_set_key(cpname, data->tokens[1] + i + 1, data);

				_print_environ(data);
				if (_env_get_key(cpname, data) == NULL)
				{
					_print(data->tokens[1]);
					_print("\n");
				}
				else
				{
					_env_set_key(cpname, var_copy, data);
					free(var_copy);
				}
				return (0);
			}
			cpname[i] = data->tokens[1][i];
		}
		errno = 2;
		perror(data->command_name);
		errno = 127;
	}
	return (0);
}

/**
 * _builtin_set_env - setenv
 * @data: data.
 *
 * Return: 0 on success.
 */

int _builtin_set_env(data_of_program *data)
{
	if (data->tokens[1] == NULL || data->tokens[2] == NULL)
		return (0);
	if (data->tokens[3] != NULL)
	{
		errno = E2BIG;
		perror(data->command_name);
		return (5);
	}

	_env_set_key(data->tokens[1], data->tokens[2], data);

	return (0);
}
