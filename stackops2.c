#include "monty.h"
/**
 * mod - divides second top by top and computes the remainder
 * @stack: stack from main
 * @line_num: line number
 */
void mod(stack_t **stack, unsigned int line_num)
{
	int value;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_num);
		exit(EXIT_FAILURE);
		return;
	}
	if (((*stack)->n) == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_num);
		exit(EXIT_FAILURE);
		return;
	}

	value = ((*stack)->next->n) % ((*stack)->n);
	pop(stack, line_num);
	(*stack)->n = value;
}

/**
 * pchar - prints the char at the top of the stack
 * @stack: stack from main
 * @line_num: line number
 */
void pchar(stack_t **stack, unsigned int line_num)
{
	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_num);
		exit(EXIT_FAILURE);
		return;
	}
	if (isascii((*stack)->n) == 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_num);
		exit(EXIT_FAILURE);
		return;
	}
	printf("%c\n", (*stack)->n);
}

/**
 * pstr - prints the string starting at the top of the stack
 * @stack: stack from main
 * @line_num: line number
 */
void pstr(stack_t **stack, unsigned int line_num __attribute__((unused)))
{
	stack_t *active = *stack;

	while (active)
	{
		if (active->n <= 0 || active->n > 127)
			break;
		putchar((char) active->n);
		active = active->next;
	}
	putchar('\n');
}

/**
 * rotl - rotates the stack to the top
 * @stack: stack from main
 * @line_count: line number
 */
void rotl(stack_t **stack, unsigned int line_count)
{
	stack_t *left;
	stack_t *right;

	(void) line_count;
	if (!stack || !*stack || !(*stack)->next)
		return;

	left = right = *stack;

	while (right->next)
		right = right->next;
	right->next = left;
	left->prev = right;
	*stack = left->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}

/**
* rotr - rotates the stack to the bottom
* @stack: stack from main
* @line_count: line number
*/
void rotr(stack_t **stack, unsigned int line_count)
{
	stack_t *last;
	stack_t *prev;

	(void) line_count;
	if (!stack || !*stack || !(*stack)->next)
		return;

	last = *stack;

	while (last->next)
		last = last->next;

	prev = last->prev;
	last->next = *stack;
	last->prev = NULL;
	prev->next = NULL;
	(*stack)->prev = last;
	*stack = last;
}
