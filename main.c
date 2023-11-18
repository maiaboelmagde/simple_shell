#include "shell.h"
/**
 * main - main function.
 * @ac: argumnents counter.
 * @argv: Arguments.
 * @environment: env
 * Return: the status of last execute.
 */
int main(int ac, char **argv, char **environment)
{
	int status = 0, index = 0, i = 0;
	char *line = NULL, *env = NULL;
	char **commandLine = NULL;
	int j = 1;
	fileIN file;

	if (ac == 2)
	{
		file = get_file_input(argv);
		j = file.len;
	}
	while (j)
	{
		if (ac == 2)
		{
			j--;
			line = file.lines[i++];
		}
		else
			line = getLine();
		if (line == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			free(env);
			return (status);
		}
		index++;
		commandLine = splitLine(line);
		comments_handler(&commandLine);
		if (!commandLine)
			continue;
		replace_variable(commandLine, status);

		if (is_builtin(commandLine[0]))
			handle_builtin(commandLine, argv, &status, index, &env);
		else
			status = _execute(commandLine, argv, index, environment);
	}
	return (0);
}
