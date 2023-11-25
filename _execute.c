#include "shell.h"


/**
 * _execute - execute cmd.
 * @data: data.
 *
 * Return: 0 on success.
 */

int _execute(data_of_program *data)
{
	int retval = 0, status;
	pid_t pidd;

	retval = _builtins_list(data);
	if (retval != -1)
		return (retval);

	retval = _find_program(data);
	if (retval)
	{
		return (retval);
	}
	else
	{
		pidd = fork();
		if (pidd == -1)
		{
			perror(data->command_name);
			exit(EXIT_FAILURE);
		}
		if (pidd == 0)
		{
			retval = execve(data->tokens[0], data->tokens, data->env);
			if (retval == -1)
				perror(data->command_name), exit(EXIT_FAILURE);
		}
		else
		{
			wait(&status);
			if (WIFEXITED(status))
				errno = WEXITSTATUS(status);
			else if (WIFSIGNALED(status))
				errno = 128 + WTERMSIG(status);
		}
	}
	return (0);
}
