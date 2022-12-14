#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
* pop - removes the top element of the stack
* @stack: stack from main
* @line_num: line number
*/
void pop(stack_t **stack, unsigned int line_num)
{
	stack_t *cursor = NULL;

	if (!stack || !*stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_num);
		exit(EXIT_FAILURE);
	}

	cursor = (*stack)->next;
	free(*stack);
	*stack = cursor;
	if (!*stack)
		return;
	(*stack)->prev = NULL;
}

/**
 * pall - prints all the values on the stack from the top of the stack.
 * @stack: stack from main
 * @line_num: number of lines
 */
void pall(stack_t **stack, unsigned int line_num __attribute__((unused)))
{
	print_stack(*stack);
}
/**
 * push - push an element to the stack top
 * @stack: stack from main
 * @line_num: number of lines
 */
void push(stack_t **stack, unsigned int line_num)
{
	char *n = global.argument;

	if ((is_digit(n)) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_num);
		exit(EXIT_FAILURE);
	}

	if (global.data_struct == 1)
	{
		if (!add_node(stack, atoi(global.argument)))
		{
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		if (!queue_node(stack, atoi(global.argument)))
		{
			exit(EXIT_FAILURE);
		}
	}
}

/**
 * pint - prints value at stacktop
 * @stack: stack from main
 * @line_num: number of lines
 */
void pint(stack_t **stack, unsigned int line_num)
{
	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_num);
		exit(EXIT_FAILURE);

	}
	printf("%d\n", (*stack)->n);
}

/**
 * swap -  swaps the top two elements of the stack
 * @stack: stack from main
 * @line_num: number of lines
 */
void swap(stack_t **stack, unsigned int line_num)
{
	stack_t *cursor = NULL;
	int cursor_n = 0;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	cursor = *stack;
	cursor_n = cursor->n;
	cursor->n = cursor_n;

	cursor->n = cursor->next->n;
	cursor->next->n = cursor_n;
}

