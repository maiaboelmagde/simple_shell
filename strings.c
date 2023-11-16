#include "shell.h"

/**
 * _strlen - returns the length of a string.
 * @s: char pointer
 * Return: the length of *s
 */
int _strlen(char *s)
{
	int length;

	length = 0;
	if (s[0] == '\0')
		return (0);

	while (s[length] != '\0')
	{
		length++;
	}
	return (length);
}

/**
 * _strcmp - compares too strings
 * @s1: first string
 * @s2: sec string
 * Return: 0
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; ((s1[i] != '\0') || (s2[i] != '\0')); i++)
	{
		if (s1[i] - s2[i] != 0)
			return (s1[i] - s2[i]);
	}
	return (0);
}

/**
 * _strdup - creates an array of chars
 * @str: array size
 * Return: array refrance or NULL
 */
char *_strdup(char *str)
{
	int length;
	char *arr;

	if (str == NULL)
		return (NULL);
	length = _strlen(str);
	arr = malloc((sizeof(char) * length) + 1);
	if (arr == NULL)
		return (NULL);
	arr[length] = '\0';
	while (length--)
		arr[length] = str[length];
	return (arr);
}

/**
 * _strcpy - copies the string pointed
 * @destination: char pointer
 * @source: char pointer
 * Return: char pinter
 */
char *_strcpy(char *destination, char *source)
{
	int i;

	for (i = 0; source[i] != '\0'; i++)
	{
		destination[i] = source[i];
	}
	destination[i] = '\0';
	return (destination);
}

/**
 * _strcat - concatenates two strings
 * @destination: char pointer left side
 * @source: char pointer right side
 * Return: the length *s
 */
char *_strcat(char *destination, char *source)
{
	int length, i;

	length = _strlen(destination);
	for (i = 0; source[i] != '\0'; i++)
	{
		destination[length + i] = source[i];
	}
	destination[length + i] = '\0';
	return (destination);
}
