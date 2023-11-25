#include "shell.h"

void  _free_array_of_pointers(char **array);
void _free_recurrent_data(data_of_program *data);
void _free_all_data(data_of_program *data);


/**
 *  _free_array_of_pointers - freeing pointers.
 * @array: array.
 *
 * Return: return nothing.
 */
void  _free_array_of_pointers(char **array)
{
	int i;

	if (array != NULL)
	{
		for (i = 0; array[i]; i++)
			free(array[i]);

		free(array);
		array = NULL;
	}
}

/**
 * _free_recurrent_data - free data.
 * @data: data.
 *
 * Return: return nothing.
 */

void _free_recurrent_data(data_of_program *data)
{
	if (data->tokens)
		_free_array_of_pointers(data->tokens);
	if (data->input_line)
		free(data->input_line);
	if (data->command_name)
		free(data->command_name);

	data->input_line = NULL;
	data->command_name = NULL;
	data->tokens = NULL;
}

/**
 * _free_all_data - data to be freed.
 * @data: data.
 *
 * Return: return nothing.
 */
void _free_all_data(data_of_program *data)
{
	if (data->file_descriptor != 0)
	{
		if (close(data->file_descriptor))
			perror(data->program_name);
	}
	_free_recurrent_data(data);
	 _free_array_of_pointers(data->env);
	 _free_array_of_pointers(data->alias_list);
}
