#include "monty.h"

/**
 * rotl - rotates the first element of the stack
 * @stack: stack head
 * @line_count: line count
 *
 * Return: void
 */
void rotl(stack_t **stack, unsigned int line_count)
{
	stack_t *left;
	stack_t *right;

	(void)line_count;
	if (!stack || !*stack || !(*stack)->next)
		return;

	left = right = *stack;

	while (right->next) /* move the right pointer to the last node */
		right = right->next;

	right->next = left; /* create a circular linked list loop */
	left->prev = right;
	*stack = left->next; /* update the stack head to the second node */
	(*stack)->prev->next = NULL; /* break the link between the first and second node */
	(*stack)->prev = NULL;
}
