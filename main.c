#include "shell.h"

/**
 * main - main.
 * @argc: argc.
 * @argv: arguments values.
 * @env: env
 *
 * Return: 0 on Success.
 */
int main(int argc, char *argv[], char *env[])
{
	data_of_program data_struct = {NULL}, *data = &data_struct;
	char *prompt = "";

	_init_data(data, argc, argv, env);

	signal(SIGINT, _handle_ctrl_c);

	if (isatty(STDIN_FILENO) && isatty(STDOUT_FILENO) && argc == 1)
	{
		errno = 2;
		prompt = PROMPT_MSG;
	}
	errno = 0;
	_sisifo(prompt, data);
	return (0);
}

/**
 * _handle_ctrl_c - [Ctrl + C]
 * @UNUSED: option.
 */
void _handle_ctrl_c(int opr UNUSED)
{
	_print("\n");
	_print(PROMPT_MSG);
}
