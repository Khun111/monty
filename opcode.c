#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./monty.h"

/**
 * opcode - handles instructions
 * @stack: stack in main function
 * @str: string to compare
 * @line_num: amount of lines
 */
void opcode(stack_t **stack, char *str, unsigned int line_num)
{
	int i = 0;

	instruction_t op[] = OPCODES;

	if (!strcmp(str, "stack"))
	{
		global.data_struct = 1;
		return;
	}
	if (!strcmp(str, "queue"))
	{
		global.data_struct = 0;
		return;
	}

	while (op[i].opcode)
	{
		if (strcmp(op[i].opcode, str) == 0)
		{
			op[i].f(stack, line_num);
			return; /* run the function if it matches the instuction */
		}
		i++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_num, str);
	exit(EXIT_FAILURE);
}
