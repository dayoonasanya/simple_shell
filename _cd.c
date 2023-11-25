#include "shell.h"

int _set_work_directory(data_of_program *data, char *new_dir);
int _builtin_cd(data_of_program *data);

/**
 * _set_work_directory - set dir.
 * @data: data.
 * @new_dir: new path.
 *
 * Return: 0 on success.
 */

int _set_work_directory(data_of_program *data, char *new_dir)
{
	char old_dir[128] = {0};
	int err_code = 0;

	getcwd(old_dir, 128);

	if (!_str_compare(old_dir, new_dir, 0))
	{
		err_code = chdir(new_dir);
		if (err_code == -1)
		{
			errno = 2;
			return (3);
		}
		_env_set_key("PWD", new_dir, data);
	}
	_env_set_key("OLDPWD", old_dir, data);
	return (0);
}

/**
 * _builtin_cd - cd.
 * @data: data.
 *
 * Return: 0 on success.
 */
int _builtin_cd(data_of_program *data)
{
	char *dir_home = _env_get_key("HOME", data), *dir_old = NULL;
	char old_dir[128] = {0};
	int error_code = 0;

	if (data->tokens[1])
	{
		if (_str_compare(data->tokens[1], "-", 0))
		{
			dir_old = _env_get_key("OLDPWD", data);
			if (dir_old)
				error_code = _set_work_directory(data, dir_old);
			_print(_env_get_key("PWD", data));
			_print("\n");

			return (error_code);
		}
		else
		{
			return (_set_work_directory(data, data->tokens[1]));
		}
	}
	else
	{
		if (!dir_home)
			dir_home = getcwd(old_dir, 128);

		return (_set_work_directory(data, dir_home));
	}
	return (0);
}
