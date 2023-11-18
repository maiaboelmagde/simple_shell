#include "shell.h"
/**
 * getEnv - a function that gets an environment variable.
 * @variable: the variable name.
 * Return: the environment variable.
*/
char *getEnv(char *variable)
{
	char *key, *tmp, *env;
	int i;

	for (i = 0; environ[i]; i++)
	{
		tmp = _strdup(environ[i]);
		key = strtok(tmp, "=");
		if (_strcmp(key, variable) == 0)
		{
			env = _strdup(strtok(NULL, "\n"));
			free(tmp);
			return (env);
		}
		free(tmp);
	}

	return (NULL);
}
/**
 * build_p	th_list - a function that builds a linked list
 * of the PATH directories.
 * Return: a linked list of the PATH directories.
*/
list_path *buildDirList(void)
{
	list_path *head = NULL;
	char *path_env, *token;

	path_env = getEnv("PATH");
	if (!path_env)
		return (NULL);
	token = strtok(path_env, ":");
	while (token)
	{
		add_node_end(&head, token);
		token = strtok(NULL, ":");
	}
	free(path_env);
	return (head);
}
/**
 * getPath - a function that handle the path of a command.
 * @command: the command to handle.
 * Return: the full path of the command.
*/
char *getPath(char *command)
{
	list_path *ld, *tmp;
	char *path;
	struct stat st;
	int i;

	for (i = 0; command[i]; i++)
	{
		if (command[i] == '/') /* Check if command is already a path */
		{
			if (stat(command, &st) == 0) /* If the path is valid, return it */
				return (_strdup(command));
			return (NULL);
		}
	}
	ld = buildDirList(); /* Build list of path directories */
	tmp = ld;
	while (tmp)
	{
		/* size = len(directory) + len(command) + 2 ('/' and '\0') */
		path = malloc(_strlen(tmp->dir) + _strlen(command) + 2);
		if (!path)
		{
			free_list_dir(ld);
			return (NULL);
		}
		_strcpy(path, tmp->dir);
		_strcat(path, "/");
		_strcat(path, command);
		if (stat(path, &st) == 0) /* If the path is valid return it */
		{
			free_list_dir(ld);
			return (path);
		}
		free(path), path = NULL;
		tmp = tmp->next;
	}
	free_list_dir(ld);
	return (NULL);
}
