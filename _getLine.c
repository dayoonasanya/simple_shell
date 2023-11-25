#include "shell.h"

int _get_line(data_of_program *data);

/**
* _get_line - read.
* @data: data.
*
* Return: returning bytes.
*/
int _get_line(data_of_program *data)
{
	char buffer[BUFFER_SIZE] = {'\0'};
	static char *array_of_commands[10] = {NULL};
	static char array_operators[10] = {'\0'};
	ssize_t bytes_read, i = 0;

	if (!array_of_commands[0] || (array_operators[0] == '&' && errno != 0) ||
		(array_operators[0] == '|' && errno == 0))
	{
		for (i = 0; array_of_commands[i]; i++)
		{
			free(array_of_commands[i]);
			array_of_commands[i] = NULL;
		}

		bytes_read = read(data->file_descriptor, &buffer, BUFFER_SIZE - 1);
		if (bytes_read == 0)
			return (-1);

		i = 0;
		do {
			array_of_commands[i] = _str_duplicate(_strtok(i ? NULL : buffer, "\n;"));
			i = _check_logic_ops(array_of_commands, i, array_operators);
		} while (array_of_commands[i++]);
	}

	data->input_line = array_of_commands[0];
	for (i = 0; array_of_commands[i]; i++)
	{
		array_of_commands[i] = array_of_commands[i + 1];
		array_operators[i] = array_operators[i + 1];
	}

	return (_str_length(data->input_line));
}
