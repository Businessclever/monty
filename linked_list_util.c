#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * queue_node - adds a node to a stack_t stack in queue node
 * @stack: stack head
 * @n: number of the node
 *
 * Return: newly created node, if memory allocation fails, the function will
 * return NULL.
 */
stack_t *queue_node(stack_t **stack, const int n)
{
	stack_t *new = malloc(sizeof(stack_t));
	stack_t *current;

	if (!new)
	{
		free(new);
		return (NULL);
	}
	new->n = n;
	new->prev = NULL;
	new->next = NULL;

	if (!*stack)
	{
		*stack = new;
		return (new);
	}

	current = *stack;
	while (current->next)
		current = current->next;

	new->prev = current;
	current->next = new;

	return (new);
}

/**
 * add_node - adds a node to the start of a stack_t stack
 * @stack: stack head
 * @n: number for the new node
 *
 * Return: newly created node, if creation fails, the
 * function will return NULL.
 */
stack_t *add_node(stack_t **stack, const int n)
{
	stack_t *new = malloc(sizeof(stack_t));

	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(new);
		return (NULL);
	}
	new->n = n;
	new->prev = NULL;
	new->next = *stack;

	if (*stack)
		(*stack)->prev = new;

	*stack = new;

	return (new);
}

/**
 * print_stack - prints the contents of a stack_t stack
 * @stack: stack head
 *
 * Return: number of elements of the list
 */
size_t print_stack(const stack_t *stack)
{
	const stack_t *current = stack;
	size_t count = 0;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
		count++;
	}

	return (count);
}

/**
 * free_stack - frees a dlistint_t linked list
 * @stack: list head
 *
 * Return: void
 */
void free_stack(stack_t *stack)
{
	stack_t *current;

	while (stack)
	{
		current = stack;
		stack = stack->next;
		free(current);
	}
}
