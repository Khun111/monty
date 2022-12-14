#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
* pop - removes the top element of the stack
* @stack: stack given by main in start.c
* @line_num: line number for error messages
*
* Return: void
*/
void pop(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp = NULL;

	if (!stack || !*stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_num);
		exit(EXIT_FAILURE);
	}

	tmp = (*stack)->next;
	free(*stack);
	*stack = tmp;
	if (!*stack)
		return; /* prevents errors cause next line might assign a NULL */
	(*stack)->prev = NULL;
}

/**
 * pall - prints the stack
 * @stack: stack given by main in start.c
 * @line_num: amount of lines
 *
 * Return: void
 */
void pall(stack_t **stack, unsigned int line_num __attribute__((unused)))
{
	print_stack(*stack);
}
/**
 * push - push element into the stack
 * @stack: stack given by main
 * @line_num: amount of lines
 *
 * Return: void
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
 * pint - print the value at the top of the stack
 * @stack: stack given by main in start.c
 * @line_num: amount of lines
 *
 * Return: void
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
 * swap -  swaps data from top to previous
 * @stack: stack given by main
 * @line_num: amount of lines
 *
 * Return: void
 */
void swap(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp = NULL;
	int tmp_n = 0;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	tmp_n = tmp->n;
	tmp->n = tmp_n;

	tmp->n = tmp->next->n;
	tmp->next->n = tmp_n;
}

