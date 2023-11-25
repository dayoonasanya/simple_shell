/**
 * _builtin_unset_env - unsetenv.
 * @data: data.
 *
 * Return: 0 on success.
 */
int _builtin_unset_env(data_of_program *data)
{
	if (data->tokens[1] == NULL)
		return (0);
	if (data->tokens[2] != NULL)
	{
		errno = E2BIG;
		perror(data->command_name);
		return (5);
	}
	_env_remove_key(data->tokens[1], data);

	return (0);
}
