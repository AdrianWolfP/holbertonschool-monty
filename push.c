#include "monty.h"

/**
 * push - push element to stack
 * @stack: stack, to the top of which an element is to be pushed
 * @line_n: line number within monty instruction file
 */

void push(stack_t **stack, size_t line_n)
{
	int i = 0, invalid = 0;
	char *value = NULL;
	stack_t *top = NULL;

	value = strtok(NULL, SPC_DELIM);

	if (!value)
	{
		fprintf(stderr, "L%lu: usage: push integer\n", line_n);
		freeStack(stack);
		exit(EXIT_FAILURE);
	}
	for (invalid = 0; value[i]; i++)
	{
		if (i == 0 && value[i] == '-')
			i++;
		if (value[i] < '0' || value[i] > '9')
			invalid = 1;
	}
	if (invalid)
	{
		fprintf(stderr, "L%lu: usage: push integer\n", line_n);
		freeStack(stack);
		exit(EXIT_FAILURE);
	}
	top = malloc(sizeof(stack_t));
	if (!top)
	{
		fprintf(stderr, "Error: malloc failed\n");
		freeStack(stack);
		exit(EXIT_FAILURE);
	}
	top->n = atoi(value);
	top->prev = NULL;
	top->next = *stack;
	if (*stack)
		(*stack)->prev = top;
	*stack = top;
}