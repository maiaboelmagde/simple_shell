#include "shell.h"
/**
 * replace_variable- variable replacement.
 * @command: the current command.
 * @status: the exit status of the last command.
 * Return: (void)
*/
void replace_variable(char **command, int status)
{
	int i;
	char *replace = NULL, *str, c;

	for (i = 0; command[i]; i++)
	{
		if (command[i][0] == '$')
		{
			c = command[i][1];
			if (c == '?')
				replace = _itoa(status);

			else if (c == '$')
				replace = _itoa((int) getpid());
			else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
			{
				str = command[i];
				str++;
				replace = getEnv(str);
				if (!replace)
					replace = strdup("");
			}
			if (replace)
				free(command[i]), command[i] = replace;
		}
	}
}
