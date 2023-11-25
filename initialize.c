#include "shell.h"

/**
 * _init_data - init struct.
 * @data: data.
 * @argv: array argument.
 * @env: env.
 * @argc: argument.
 */
void _init_data(data_of_program *data, int argc, char *argv[], char **env)
{
	int i = 0;

	data->program_name = argv[0];
	data->input_line = NULL;
	data->command_name = NULL;
	data->exec_counter = 0;
	if (argc == 1)
		data->file_descriptor = STDIN_FILENO;
	else
	{
		data->file_descriptor = open(argv[1], O_RDONLY);
		if (data->file_descriptor == -1)
		{
			_printe(data->program_name);
			_printe(": 0: Can't open ");
			_printe(argv[1]);
			_printe("\n");
			exit(127);
		}
	}
	data->tokens = NULL;
	data->env = malloc(sizeof(char *) * 50);
	if (env)
	{
		for (; env[i]; i++)
		{
			data->env[i] = _str_duplicate(env[i]);
		}
	}
	data->env[i] = NULL;
	env = data->env;

	data->alias_list = malloc(sizeof(char *) * 20);
	for (i = 0; i < 20; i++)
	{
		data->alias_list[i] = NULL;
	}
}

/**
 * _sisifo - prompt loop.
 * @prompt: prompt.
 * @data: data.
 */
void _sisifo(char *prompt, data_of_program *data)
{
	int error_code = 0, string_len = 0;

	while (++(data->exec_counter))
	{
		_print(prompt);
		error_code = string_len = _get_line(data);

		if (error_code == EOF)
		{
			_free_all_data(data);
			exit(errno);
		}
		if (string_len >= 1)
		{
			_expand_alias(data);
			_expand_variables(data);
			_tokenize(data);
			if (data->tokens[0])
			{
				error_code = _execute(data);
				if (error_code != 0)
					_print_error(error_code, data);
			}
			_free_recurrent_data(data);
		}
	}
}
