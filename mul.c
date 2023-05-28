#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

void _mul(stack_t **stack, unsigned int line_cnt)
{
	int result;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_cnt);
		status = EXIT_FAILURE;
		return;
	}

	result = ((*stack)->next->n) * ((*stack)->n);
	pop(stack, line_cnt);
	(*stack)->n = result;
}
