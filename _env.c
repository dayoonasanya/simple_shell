#include "shell.h"

int _env_set_key(char *key, char *value, data_of_program *data);
char *_env_get_key(char *key, data_of_program *data);
int _env_remove_key(char *key, data_of_program *data);


/**
 * _env_set_key - set key.
 * @key: key.
 * @value: value.
 * @data: data.
 *
 * Return: NULL
 */

int _env_set_key(char *key, char *value, data_of_program *data)
{
	int i, key_length = 0, is_new_key = 1;

	if (key == NULL || value == NULL || data->env == NULL)
		return (1);

	key_length = _str_length(key);

	for (i = 0; data->env[i]; i++)
	{
		if (_str_compare(key, data->env[i], key_length) &&
		 data->env[i][key_length] == '=')
		{
			is_new_key = 0;
			free(data->env[i]);
			break;
		}
	}
	data->env[i] = _str_concat(_str_duplicate(key), "=");
	data->env[i] = _str_concat(data->env[i], value);

	if (is_new_key)
	{
		data->env[i + 1] = NULL;
	}
	return (0);
}

/**
 * _env_get_key - value.
 * @key: key.
 * @data: data.
 *
 * Return: pointer.
 */
char *_env_get_key(char *key, data_of_program *data)
{
	int i, key_length = 0;

	if (key == NULL || data->env == NULL)
		return (NULL);

	key_length = _str_length(key);

	for (i = 0; data->env[i]; i++)
	{
		if (_str_compare(key, data->env[i], key_length) &&
		 data->env[i][key_length] == '=')
		{
			return (data->env[i] + key_length + 1);
		}
	}
	return (NULL);
}


/**
 * _env_remove_key - key.
 * @key: key.
 * @data: data.
 *
 * Return: 0 on success.
 */

int _env_remove_key(char *key, data_of_program *data)
{
	int i, key_length = 0;

	if (key == NULL || data->env == NULL)
		return (0);

	key_length = _str_length(key);

	for (i = 0; data->env[i]; i++)
	{
		if (_str_compare(key, data->env[i], key_length) &&
		 data->env[i][key_length] == '=')
		{
			free(data->env[i]);
			i++;
			for (; data->env[i]; i++)
			{
				data->env[i - 1] = data->env[i];
			}
			data->env[i - 1] = NULL;
			return (1);
		}
	}
	return (0);
}
