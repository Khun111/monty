#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"
/**
 * _add -  adds the first two nodes of the stack
 * @stack: stack given by main
 * @line_num: line counter
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
	pop(stack, line_num); /*For top node*/
	(*stack)->n = value;
}

#include "monty.h"

/**
 * nop -  does nothing
 * @stack: doesnt matter
 * @line_num : for nothing
 */
void nop(stack_t **stack, unsigned int line_num)
{
	(void) stack;
	(void) line_num;
}
/**
 * _sub -  substracts the first two nodes of the stack
 * @stack: stack given by main
 * @line_num: line counter
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
	pop(stack, line_num);/*For top node*/
	(*stack)->n = value;
}

/**
 * _div - divides the next top value by the top value
 * @stack: stack given by main
 * @line_num: line counter
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
	pop(stack, line_num);/*For top node*/
	(*stack)->n = value;
}

/**
 * _mul - divides the next top value by the top value
 * @stack: stack given by main
 * @line_num: line counter
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
	pop(stack, line_num);/*For top node*/
	(*stack)->n = value;
}
