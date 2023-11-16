#include "shell.h"

void _perror(char *name, char *command, int index)
{
	char *id, message[] = ": not found\n";

	id = _atoi(index);
	write(STDERR_FILENO, name, _strlen(name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, id, _strlen(id));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, command, _strlen(command));
	write(STDERR_FILENO, message, _strlen(message));

	free(id);
}

char *_atoi(int n)
{
	char buffer[20];
	int i = 0;

	if (n == 0)
		buffer[i++] = '0';
	else
	{
		while (n > 0)
		{
			buffer[i++] = (n % 10) + '0';
			n /= 10;
		}
	}
	buffer[i] = '0';
	revString(buffer, i);

	return (_strdup(buffer));
}

void revString(char *str, int length)
{
	char temp;
	int start = 0, end = length - 1;

	while (start < end)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
}
