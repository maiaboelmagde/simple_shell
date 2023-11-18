#include "shell.h"
/**
 * getLine -  prints a prompt and get input.
 * Return: the input string otherwise return NULL.
 */
char *getLine(void)
{
	char *commandLine = NULL;
	size_t length = 0;

	/* Print "$ " if stdout is a terminal (interactive mode) */
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);
	/* Get input from stdin */
	if (getline(&commandLine, &length, stdin) == -1)
	{
		/* If getline failed "EOF condition" (the user type Ctrl+D) */
		free(commandLine);
		return (NULL);
	}
	/* Return the commandLine contains the input */
	return (commandLine);
}
/**
 * splitLine - a functin that splits a string into tokens.
 * @line: the string to split.
 * Return: a null terminating array of strings, containing each word of line
 * or null if line is only delimiters.
*/
char **splitLine(char *line)
{
	int i = 0, j = 0;
	char *token, *tmp, **array = NULL;

	if (line == NULL)
		return (NULL);

	tmp = _strdup(line); /* Creat a copy of the original line */
	token = strtok(tmp, DELIMITERS); /* Try get the first token */
	if (!token) /* If there are no tokens, return NULL */
	{
		free(line), line = NULL;
		free(tmp), tmp = NULL;
		return (NULL);
	}
	while (token) /* Count the number of tokens */
	{
		j++;
		token = strtok(NULL, DELIMITERS);
	}
	free(tmp), tmp = NULL;
	/* Allocate memory for tokens array */
	array = malloc(sizeof(char *) * (j + 1));
	if (!array)
	{
		free(line), line = NULL;
		free(tmp), tmp = NULL;
		return (NULL);
	}
	token = strtok(line, DELIMITERS);
	while (token)
	{
		array[i++] = _strdup(token); /* Fill the array with tokens */
		token = strtok(NULL, DELIMITERS); /* Get the next token*/
	}
	array[i] = NULL; /* terminate the array with NULL*/
	free(line), line = NULL;

	return (array);
}
