#include "shell.h"
/**
 * comments_handler - a function that handle shell comments
 * @command: the command
 * Return: (void)
*/
void comments_handler(char ***command)
{
	int i, comment = 0;

	if (!(*command))
		return;

	for (i = 0; (*command)[i]; i++)
	{
		if ((*command)[i][0] == '#')
		{
			comment = 1;
			break;
		}
	}
	if (comment)
	{
		while ((*command)[i])
		{
			free((*command)[i]), (*command)[i] = NULL;
			i++;
		}
	}
	if (!(*command)[0])
	{
		free((*command)), (*command) = NULL;
	}
}
