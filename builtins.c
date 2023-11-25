#include "shell.h"

int _builtin_help(data_of_program *data);
int _builtin_alias(data_of_program *data);

/**
 * _builtin_help - help.
 * @data: data.
 *
 * Return: 0 on success.
 */
int _builtin_help(data_of_program *data)
{
	int i, length = 0;
	char *mensajes[6] = {NULL};

	mensajes[0] = HELP_MSG;

	if (data->tokens[1] == NULL)
	{
		_print(mensajes[0] + 6);
		return (1);
	}
	if (data->tokens[2] != NULL)
	{
		errno = E2BIG;
		perror(data->command_name);
		return (5);
	}
	mensajes[1] = HELP_EXIT_MSG;
	mensajes[2] = HELP_ENV_MSG;
	mensajes[3] = HELP_SETENV_MSG;
	mensajes[4] = HELP_UNSETENV_MSG;
	mensajes[5] = HELP_CD_MSG;

	for (i = 0; mensajes[i]; i++)
	{
		length = _str_length(data->tokens[1]);
		if (_str_compare(data->tokens[1], mensajes[i], length))
		{
			_print(mensajes[i] + length + 1);
			return (1);
		}
	}
	errno = EINVAL;
	perror(data->command_name);
	return (0);
}

/**
 * _builtin_alias - alias.
 * @data: data.
 *
 * Return: 0 on success.
 */

int _builtin_alias(data_of_program *data)
{
	int i = 0;

	if (data->tokens[1] == NULL)
		return (_print_alias(data, NULL));

	while (data->tokens[++i])
	{
		if (_count_characters(data->tokens[i], "="))
			_set_alias(data->tokens[i], data);
		else
			_print_alias(data, data->tokens[i]);
	}

	return (0);
}
