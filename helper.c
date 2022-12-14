#include "monty.h"

/**
 * is_digit - checks for digit in a string
 * @str: string to check
 *
 * Return: 1\0
 */
int is_digit(char *str)
{
	if (!str || *str == '\0')
		return (0);
	if (*str == '-')
		str++;
	while (*str)
	{
		if (isdigit(*str) == 0)
			return (0);
		str++;
	}
	return (1);
}
/**
 * is_digit - checks for number in a string
 * @str: string to check
 *
 * Return: 1\0
 */
int isnumber(char *str)
{
	int i;

	if (!str)
		return (0);

	for (i = 0; str[i]; i++)
		if (i < '0' || i > '9')
			return (0);

	return (1);
}
