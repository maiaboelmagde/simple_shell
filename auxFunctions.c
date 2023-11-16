#include "shell.h"
void freeArr(char **arr)
{
	int i;

	if (!arr)
		return;

	for (i = 0; arr[i]; i++)
	{
		free(arr[i]);
		arr[i] = NULL;
	}
	free(arr), arr = NULL;
}


int _execute(char **command, char **argv, char **environment, int index)
{
	char *commandLine;
	pid_t pid;
	int status;

	commandLine = _getpath(command[0]);
	if	(!commandLine)
	{
		_perror(argv[0], command[0], index);
		freeArr(command);
		return (127);
	}
	pid = fork();
	if (pid == 0)
	{
		if (execve(commandLine, command, environment) == -1)
		{
			free(commandLine), commandLine = NULL;
			freeArr(command);
		}
	}
	else
	{
	   waitpid(pid, &status, 0);
	   freeArr(command);
	   free(commandLine), commandLine = NULL;
	}
	return (WEXITSTATUS(status));
}

char *_getenv(char *name)
{
	int i = 0, j = 0;

	if (name == NULL)
		return (NULL);
	while (environ[i])
	{
		j = 0;
		while (environ[i][j] != '=')
		{
			if (environ[i][j] != name[j])
				break;
			if (environ[i][j] == name[j] && (environ[i][j + 1] == '='))
				return (&environ[i][_strlen(name) + 1]);
			j++;
		}
		i++;
	}
	return (NULL);
}

char *_getpath(char *commandLine)
{
	char *command, *directory;
	struct stat stt;
	int i;

	for (i = 0; commandLine[i]; i++)
	{
		if (commandLine[i] == '/')
		{
			if (stat(commandLine, &stt) == 0)
			{
				return (_strdup(commandLine));

			return (NULL);
			}
		}
	}
	if (!_getenv("PATH"))
		return (NULL);
	directory = strtok(_getenv("PATH"), ":");
	while (directory)
	{
		command = malloc(_strlen(directory) * _strlen(commandLine));
		if (command)
		{
			_strcpy(command, directory);
			_strcat(command, "/");
			_strcat(command, commandLine);
			if (stat(command, &stt) == 0)
				return (command);
		}
		free(command), command = NULL;
		directory = strtok(NULL, ":");
	}
	return (NULL);
}
