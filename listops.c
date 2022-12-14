#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * queue_node - adds new node to stack_t head as a queue
 * @head: head
 * @n: node data
 *
 * Return: new node
 */
stack_t *queue_node(stack_t **head, const int n)
{
	stack_t *new = malloc(sizeof(stack_t));
	stack_t *current = *head;

	if (!new)
	{
		free(new);
		return (NULL);
	}
	new->n = n;

	if (!*head)
	{
		new->next = NULL;
		new->prev = NULL;
		*head = new;
		return (new);
	}

	while (current)
	{
		if (!current->next)
		{
			new->next = NULL;
			new->prev = current;
			current->next = new;
			break;
		}
		current = current->next;
	}

	return (new);
}

/**
 * add_node - adds new node to stack_t head as a stack
 * @head: head
 * @n: node data
 *
 * Return: new node
 */
stack_t *add_node(stack_t **head, const int n)
{
	stack_t *new = malloc(sizeof(stack_t));

	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(new);
		return (NULL);
	}
	new->n = n;

	new->next = *head;
	new->prev = NULL;
	if (*head)
		(*head)->prev = new;

	*head = new;

	return (new);
}

/**
 * print_stack - prints node items
 * @head: head
 *
 * Return: number of items
 */
size_t print_stack(const stack_t *head)
{
	size_t c = 0;

	while (head)
	{
		printf("%d\n", head->n);
		head = head->next;
		c++;
	}

	return (c);
}

/**
 * free_stack - frees list
 * @head: head
 */
void free_stack(stack_t *head)
{
	stack_t *current = head;
	stack_t *next;

	if (head)
	{
		next = head->next;
		while (current)
		{
			free(current);
			current = next;
			if (next)
				next = next->next;
		}
	}
}
