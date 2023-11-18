#include "shell.h"

/**
 * _execute - a function that executes a command.
 * @command: the command to execute.
 * @argv: arguments.
 * @idx: command index.
 * Return: the exit status of child processe
 * or 127 if the command does not exist.
*/
int _execute(char **command, char **argv, int idx, char **environment)
{
	pid_t child;
	char *cmd;
	int status;
	(void)environment;

	/* Get the path of the first command argument */
	cmd = getPath(command[0]);

	if (!cmd)  /* If the command does not exist dont call fork */
	{
		print_error(argv[0], idx, command[0]);
		free2Darray(command);
		return (127);
	}
	child = fork();
	if (child == 0)
	{
		if (execve(cmd, command, environ) == -1)
		{
			free2Darray(command);
			free(cmd), cmd = NULL;
		}
	}
	else
	{
		waitpid(child, &status, 0);
		free2Darray(command);
		free(cmd), cmd = NULL;
	}

	return (WEXITSTATUS(status));
}
