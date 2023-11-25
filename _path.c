#include "shell.h"

int _find_program(data_of_program *data);
char **__tokenize_path(data_of_program *data);
int _check_file(char *full_path);

/**
 * _find_program - program finder.
 * @data: data.
 *
 * Return: 0 on success.
 */
int _find_program(data_of_program *data)
{
	int i = 0, ret_code = 0;
	char **directories;

	if (!data->command_name)
		return (2);

	if (data->command_name[0] == '/' || data->command_name[0] == '.')
		return (_check_file(data->command_name));

	free(data->tokens[0]);
	data->tokens[0] = _str_concat(_str_duplicate("/"), data->command_name);
	if (!data->tokens[0])
		return (2);

	directories = __tokenize_path(data);

	if (!directories || !directories[0])
	{
		errno = 127;
		return (127);
	}
	for (i = 0; directories[i]; i++)
	{
		directories[i] = _str_concat(directories[i], data->tokens[0]);
		ret_code = _check_file(directories[i]);
		if (ret_code == 0 || ret_code == 126)
		{
			errno = 0;
			free(data->tokens[0]);
			data->tokens[0] = _str_duplicate(directories[i]);
			 _free_array_of_pointers(directories);
			return (ret_code);
		}
	}
	free(data->tokens[0]);
	data->tokens[0] = NULL;
	 _free_array_of_pointers(directories);
	return (ret_code);
}

/**
 * __tokenize_path - tokenize path.
 * @data: data.
 *
 * Return: array.
 */
char **__tokenize_path(data_of_program *data)
{
	int i = 0;
	int counter_directories = 2;
	char **tokens = NULL;
	char *PATH;

	PATH = _env_get_key("PATH", data);
	if ((PATH == NULL) || PATH[0] == '\0')
	{
		return (NULL);
	}

	PATH = _str_duplicate(PATH);

	for (i = 0; PATH[i]; i++)
	{
		if (PATH[i] == ':')
			counter_directories++;
	}

	tokens = malloc(sizeof(char *) * counter_directories);

	i = 0;
	tokens[i] = _str_duplicate(_strtok(PATH, ":"));
	while (tokens[i++])
	{
		tokens[i] = _str_duplicate(_strtok(NULL, ":"));
	}

	free(PATH);
	PATH = NULL;
	return (tokens);

}

/**
 * _check_file - run file checks.
 * @full_path: pointer.
 *
 * Return: 0 on success.
 */
int _check_file(char *full_path)
{
	struct stat sb;

	if (stat(full_path, &sb) != -1)
	{
		if (S_ISDIR(sb.st_mode) ||  access(full_path, X_OK))
		{
			errno = 126;
			return (126);
		}
		return (0);
	}
	errno = 127;
	return (127);
}
