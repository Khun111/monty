#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"
/**
 * _add -  adds the top two elements of the stack
 * @stack: stack from main
 * @line_num: line number
 */
void _add(stack_t **stack, unsigned int line_num)
{
	int value;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

	value = ((*stack)->next->n) + ((*stack)->n);
	pop(stack, line_num);
	(*stack)->n = value;
}

/**
 * nop -  doesn’t do anything
 * @stack: nil
 * @line_num: nil
 */
void nop(stack_t **stack, unsigned int line_num)
{
	(void) stack;
	(void) line_num;
}
/**
 * _sub -  subtracts the top element from the second top element
 * @stack: stack from main
 * @line_num: line number
 */
void _sub(stack_t **stack, unsigned int line_num)
{
	int value;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

	value = ((*stack)->next->n) - ((*stack)->n);
	pop(stack, line_num);
	(*stack)->n = value;
}

/**
 * _div - divides the second top element by the top element
 * @stack: stack from main
 * @line_num: line number
 */
void _div(stack_t **stack, unsigned int line_num)
{
	int value;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	if (((*stack)->n) == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_num);
		exit(EXIT_FAILURE);
		;
		return;
	}

	value = ((*stack)->next->n) / ((*stack)->n);
	pop(stack, line_num);
	(*stack)->n = value;
}

/**
 * _mul - multiplies the second top element by the top element
 * @stack: stack from main
 * @line_num: line number
 */
void _mul(stack_t **stack, unsigned int line_num)
{
	int value;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_num);
		exit(EXIT_FAILURE);
		return;
	}

	value = ((*stack)->next->n) * ((*stack)->n);
	pop(stack, line_num);
	(*stack)->n = value;
}
