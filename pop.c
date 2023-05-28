#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

void pop(stack_t **stack, unsigned int line_cnt)
{
	stack_t *tmp = NULL;

	if (!stack || !*stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_cnt);
		status = EXIT_FAILURE;
		return;
	}

	tmp = (*stack)->next;
	free(*stack);
	*stack = tmp;
	if (*stack)
		(*stack)->prev = NULL;
}
