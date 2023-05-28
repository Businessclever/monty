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

	if (!arg || !is_valid_integer(arg))
	{
		fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	n = atoi(arg);
	if (bus.lifi == 0)
		addnode(head, n);
	else
		addqueue(head, n);
}

/**
 * is_valid_integer - checks if a string is a valid integer
 * @str: string to check
 * Return: 1 if valid integer, 0 otherwise
 */
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

