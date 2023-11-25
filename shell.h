#ifndef SHELL_H
#define SHELL_H

#include <fcntl.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include "macros.h"

/* Global variable */
extern char **environ;

/**
 * struct info- struct for the program's data
 * @program_name: the name of the executable
 * @input_line: pointer to the input read for _get_line
 * @command_name: pointer to the first command typed by the user
 * @exec_counter: number of excecuted comands
 * @file_descriptor: file descriptor to the input of commands
 * @tokens: pointer to array of _tokenized input
 * @env: copy of the environ
 * @alias_list: array of pointers with aliases.
 */

typedef struct info
{
	char *program_name;
	char *input_line;
	char *command_name;
	int exec_counter;
	int file_descriptor;
	char **tokens;
	char **env;
	char **alias_list;
} data_of_program;

/**
 * struct builtins - struct for the builtins
 * @builtin: the name of the builtin
 * @function: the associated function to be called for each builtin
 */

typedef struct builtins
{
	char *builtin;
	int (*function)(data_of_program *data);
} builtins;

/**shell**/
void _init_data(data_of_program *data, int arc, char *argv[], char **env);
void _sisifo(char *prompt, data_of_program *data);
void _handle_ctrl_c(int opr UNUSED);

/*getLine*/
int _get_line(data_of_program *data);
int _check_logic_ops(char *array_commands[], int i, char array_operators[]);

/*String Functions*/
int _str_length(char *string);
char *_str_duplicate(char *string);
int _str_compare(char *string1, char *string2, int number);
char *_str_concat(char *string1, char *string2);
void _str_reverse(char *string);

/* _strtok*/
void _tokenize(data_of_program *data);
char *_strtok(char *line, char *delim);

/*expand vaiables*/
void _expand_variables(data_of_program *data);
void _expand_alias(data_of_program *data);
int _buffer_add(char *buffer, char *str_to_add);

/*execute*/
int _execute(data_of_program *data);

/*path*/
char **__tokenize_path(data_of_program *data);
int _find_program(data_of_program *data);

/*memory helpers*/
void _free_array_of_pointers(char **directories);
void _free_recurrent_data(data_of_program *data);
void _free_all_data(data_of_program *data);

/*builtins*/
int _builtins_list(data_of_program *data);
int _builtin_exit(data_of_program *data);
int _builtin_cd(data_of_program *data);
int _set_work_directory(data_of_program *data, char *new_dir);
int _builtin_help(data_of_program *data);
int _builtin_alias(data_of_program *data);
int _builtin_env(data_of_program *data);
int _builtin_set_env(data_of_program *data);
int _builtin_unset_env(data_of_program *data);

/*environment management*/
char *_env_get_key(char *name, data_of_program *data);
int _env_set_key(char *key, char *value, data_of_program *data);
int _env_remove_key(char *key, data_of_program *data);
void _print_environ(data_of_program *data);

/*print*/
int _print(char *string);
int _printe(char *string);
int _print_error(int errorcode, data_of_program *data);

/*numbers*/
void _long_to_string(long number, char *string, int base);
int _atoi(char *s);
int _count_characters(char *string, char *character);

/*alias*/
int _print_alias(data_of_program *data, char *alias);
char *_get_alias(data_of_program *data, char *alias);
int _set_alias(char *alias_string, data_of_program *data);


#endif
