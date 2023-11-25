#include "shell.h"



/**
 * _print_alias - print aliases.
 * @data: data.
 * @alias: aliases.
 *
 * Return: 0 on success.
 */

int _print_alias(data_of_program *data, char *alias)
{
	int i, j, alias_length;
	char buffer[250] = {'\0'};

	if (data->alias_list)
	{
		alias_length = _str_length(alias);
		for (i = 0; data->alias_list[i]; i++)
		{
			if (!alias || (_str_compare(data->alias_list[i], alias, alias_length)
				&&	data->alias_list[i][alias_length] == '='))
			{
				for (j = 0; data->alias_list[i][j]; j++)
				{
					buffer[j] = data->alias_list[i][j];
					if (data->alias_list[i][j] == '=')
						break;
				}
				buffer[j + 1] = '\0';
				_buffer_add(buffer, "'");
				_buffer_add(buffer, data->alias_list[i] + j + 1);
				_buffer_add(buffer, "'\n");
				_print(buffer);
			}
		}
	}

	return (0);
}
