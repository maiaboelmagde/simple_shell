#include "shell.h"

char *readLine(void)
{
	char *line = NULL;
	size_t lenght = 0;
	ssize_t numberReturned;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);
	numberReturned = getline(&line, &lenght, stdin);
	if (numberReturned == -1)
	{
		free(line);
		return (NULL);
	}

	return (line);
}
