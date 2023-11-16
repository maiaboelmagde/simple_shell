#include "shell.h"
/**
 * main - Simple Shell main function
 * @ac: Arguments counter
 * @argv: Arguments vector
 * Return: 0 (success)
*/
int main(int ac, char **argv, char **env)
{
	char *line = NULL;
	char **command = NULL;
	int status = 0, index = 0;
	(void) ac;
	while (1)
	{
		line = readLine();
		if (line == NULL) /* EOF or ctr + d handling */
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1); /*new line after EOF*/
			return (status);
		}

		index++;
		command = strToken(line);
		if (!command)
			continue;

			status = _execute(command, argv, env, index);
	}
}
