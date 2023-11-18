#include "shell.h"
/**
 * free2Darray - a function that frees an array of strings.
 * @array: the array to free.
 * Return: (void).
*/
void free2Darray(char **array)
{
	int i;

	if (!array)
		return;

	for (i = 0; array[i]; i++)
	{
		free(array[i]);
		array[i] = NULL;
	}
	free(array), array = NULL;
}
/**
 * print_error - a function that prints command not found error.
 * if command doesn't exist.
 * @name: shell name.
 * @idx: the command index.
 * @cmd: the command.
 * Return: (void).
*/
void print_error(char *name, int idx, char *cmd)
{
	char *index, mssg[] = ": not found\n";

	index = _itoa(idx);

	write(STDERR_FILENO, name, _strlen(name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, index, _strlen(index));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, _strlen(cmd));
	write(STDERR_FILENO, mssg, _strlen(mssg));
	free(index);
}

/**
 * print_cd_error - a function that prints can't cd error.
 * @name: shell name.
 * @idx: the command index.
 * @path: the non existing path.
 * Return: (void).
*/
void print_cd_error(char *name, int idx, char *path)
{
	char *index, mssg[] = ": cd: can't cd to ";

	index = _itoa(idx);
	write(STDERR_FILENO, name, _strlen(name));
	write(STDERR_FILENO, ": cd: ", 2);
	write(STDERR_FILENO, index, _strlen(index));
	write(STDERR_FILENO, mssg, _strlen(mssg));
	write(STDERR_FILENO, path, _strlen(path));
	write(STDERR_FILENO, "\n", 1);

	free(index);
}

/**
 * set_wd_env - set environment for PWD and OLDPWD.
 * @env_key: environment key.
 * @env_value: environment value.
 * @new_env: new_environment variable.
 * Return: (void).
*/
void set_wd_env(char *env_key, char *env_value, char **new_env)
{
	int i;
	char *key, *variable, *tmp, *new;

	for (i = 0; environ[i]; i++)
	{
		tmp = _strdup(environ[i]);
		key = strtok(tmp, "=");
		if (_strcmp(key, env_key) == 0)
		{
			variable = strtok(NULL, "\n");
			if (_strcmp(variable, env_value) == 0)
			{
				free(tmp);
				return;
			}
			_strcpy(environ[i], env_key);
			_strcat(environ[i], "=");
			_strcat(environ[i], env_value);
			free(tmp);
			return;
		}
		free(tmp), tmp = NULL;
	}
	new = malloc(_strlen(env_key) + _strlen(env_value) + 2);
	_strcpy(new, env_key);
	_strcat(new, "=");
	_strcat(new, env_value);
	environ[i] = new, environ[i + 1] = NULL;
	(*new_env) = new;
}
