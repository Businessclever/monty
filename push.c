#include "monty.h"

/**
 * f_push - add node to the stack
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
 
void f_push(stack_t **head, unsigned int counter)
{
	int n;
	char *arg = bus.arg;

	if (arg == NULL || !is_valid_integer(arg))
		handle_error(counter);

	n = atoi(arg);
	if (bus.lifi == 0)
		addnode(head, n);
	else
		addqueue(head, n);
}


int is_valid_integer(const char *str)
{
	int i = 0;
	if (str[0] == '-')
		i++;
	for (; str[i] != '\0'; i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return 0;
	}
	return 1;
}


void handle_error(unsigned int counter)
{
	fprintf(stderr, "L%d: usage: push integer\n", counter);
	fclose(bus.file);
	free(bus.content);
	free_stack(*head);
	exit(EXIT_FAILURE);
}

