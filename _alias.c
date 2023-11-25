#include "shell.h"

int _set_alias(char *alias_string, data_of_program *data);
char *_get_alias(data_of_program *data, char *name);

/**
 * _set_alias - set alias.
 * @alias_string: alias.
 * @data: data.
 *
 * Return: 0 on success.
 */

int _set_alias(char *alias_string, data_of_program *data)
{
	int i, j;
	char buffer[250] = {'0'}, *temp = NULL;

	if (alias_string == NULL ||  data->alias_list == NULL)
		return (1);

	for (i = 0; alias_string[i]; i++)
		if (alias_string[i] != '=')
			buffer[i] = alias_string[i];
		else
		{
			temp = _get_alias(data, alias_string + i + 1);
			break;
		}

	for (j = 0; data->alias_list[j]; j++)
		if (_str_compare(buffer, data->alias_list[j], i) &&
			data->alias_list[j][i] == '=')
		{
			free(data->alias_list[j]);
			break;
		}

	if (temp)
	{
		_buffer_add(buffer, "=");
		_buffer_add(buffer, temp);
		data->alias_list[j] = _str_duplicate(buffer);
	}
	else
		data->alias_list[j] = _str_duplicate(alias_string);
	return (0);
}


/**
 * _get_alias - get alias.
 * @data: data.
 * @name: name.
 *
 * Return: 0 on success.
 */
char *_get_alias(data_of_program *data, char *name)
{
	int i, alias_length;

	if (name == NULL || data->alias_list == NULL)
		return (NULL);

	alias_length = _str_length(name);

	for (i = 0; data->alias_list[i]; i++)
	{
		if (_str_compare(name, data->alias_list[i], alias_length) &&
			data->alias_list[i][alias_length] == '=')
		{
			return (data->alias_list[i] + alias_length + 1);
		}
	}
	return (NULL);

}
