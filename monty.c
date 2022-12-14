#define  _POSIX_C_SOURCE 200809L
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "monty.h"

void error_handler(char *argv);
void usage_man(void);
int status = 0;

/**
 * main - main function
 * @argv: arguments array
 * @argc: args count
 *
 * Return: exit status
 */
int main(int argc, char **argv)
{
	FILE *file;
	size_t bufsize = 0;
	char *buffer = NULL;
	char *str = NULL;
	stack_t *stack = NULL;
	unsigned int line_num = 1;

	global.data_struct = 1;
	if (argc != 2)
		usage_man();

	file = fopen(argv[1], "r");

	if (!file)
		error_handler(argv[1]);

	while ((getline(&buffer, &bufsize, file)) != (-1))
	{
		if (status)
			break;
		if (*buffer == '\n')
		{
			line_num++;
			continue;
		}
		str = strtok(buffer, " \t\n");
		if (!str || *str == '#')
		{
			line_num++;
			continue;
		}
		global.argument = strtok(NULL, " \t\n");
		opcode(&stack, str, line_num);
		line_num++;
	}
	free(buffer);
	free_stack(stack);
	fclose(file);
	exit(EXIT_SUCCESS);
}

/**
 * error_handler - handles error messages
 * @argv: argv from main function
 */
void error_handler(char *argv)
{
	fprintf(stderr, "Error: Can't open file %s\n", argv);
	exit(EXIT_FAILURE);
}

/**
 * usage_man - prints usage messages
 */
void usage_man(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}
