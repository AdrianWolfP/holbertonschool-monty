#include "monty.h"

/**
 * pop - remove top element from stack
 * @stack: stack from which top is to be removed
 * @line_n: line number within monty instruction file
 */

void pop(stack_t **stack, size_t line_n)
{
	stack_t *del = NULL, *newtop = NULL;

	if (!stack || !*stack)
	{
		fprintf(stderr, "L%lu: can't pop an empty stack\n", line_n);
		freeStack(stack);
		exit(EXIT_FAILURE);
	}

	del = *stack;
	newtop = del->next;

	*stack = newtop;

	free(del);
}