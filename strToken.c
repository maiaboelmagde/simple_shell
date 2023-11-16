#include "shell.h"
char **strToken(char *line)
{
	char *token = NULL, *tmp = NULL;
	char **command = NULL;
	int counter = 0, i = 0;

	if (!line)
		return (NULL);
	tmp = _strdup(line);

	token = strtok(tmp, DELIMITERS);
	if (token == NULL)
	{
		free(line), line = NULL;
		free(tmp), tmp = NULL;
		return (NULL);
	}
	while (token)
	{
		counter++;
		token = strtok(NULL, DELIMITERS);
	}
	free(tmp), tmp = NULL;

	command = malloc(sizeof(char *) * (counter + 1));
	if (!command)
	{
		free(line), line = NULL;
		return (NULL);
	}

	token = strtok(line, DELIMITERS);
	while (token)
	{
		command[i] = _strdup(token);
		token = strtok(NULL, DELIMITERS);
		i++;
	}
	free(line), line = NULL;
	command[i] = NULL;
	return (command);
}
