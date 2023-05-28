#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * swap - swaps data between the top two elements of the stack
 * @stack: stack given by main
 * @line_cnt: line counter
 *
 * Return: void
 */
void swap(stack_t **stack, unsigned int line_cnt)
{
	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_cnt);
		status = EXIT_FAILURE;
		return;
	}

	int tmp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = tmp;
}

