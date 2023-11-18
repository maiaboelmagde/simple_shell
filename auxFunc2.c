#include "shell.h"

/**
 * is_positive_number - check if a string is positive number.
 * @str: the string to check.
 * Return: 1 if the string is a positive number
 * otherwise 0.
*/
int is_positive_number(char *str)
{
	int i;

	if (!str)
		return (0);
	for (i = 0; str[i]; i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}
	return (1);
}

/**
 * _atoi - convert a string to an integer.
 * @str: the string.
 * Return: numerical value of the string.
*/
int _atoi(char *str)
{
	int i, num = 0;

	for (i = 0; str[i] ; i++)
	{
		num *= 10;
		num += (str[i] - '0');
	}
	return (num);
}

/**
 * reverse_string - a function that reverse string.
 * @str: string to reverse.
 * @len: the length of the string.
 * Return: (void).
*/
void reverse_string(char *str, int len)
{
	char tmp;
	int start = 0;
	int end = len - 1;

	while (start < end)
	{
		tmp = str[start];
		str[start] = str[end];
		str[end] = tmp;
		start++;
		end--;
	}
}

/**
 * _itoa - convert an integer to string.
 * @n: the integer.
 * Return: string.
*/
char *_itoa(int n)
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

	buffer[i] = '\0';
	reverse_string(buffer, i);

	return (_strdup(buffer));
}
