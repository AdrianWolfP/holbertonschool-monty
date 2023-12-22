#include "monty.h"

/**
 * sub - subtract top 2 node values in stack, second node takes result, pop top
 * @stack: stack, top 2 elements of which to be subtracted
 * @line_n: line number within monty instruction file
 */

void sub(stack_t **stack, size_t line_n)
{
	stack_t *oldtopSUB = NULL, *newtopRES = NULL;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%lu: can't sub, stack too short\n", line_n);
		freeStack(stack);
		exit(EXIT_FAILURE);
	}

	oldtopSUB = *stack;
	newtopRES = oldtopSUB->next;
	newtopRES->n -= oldtopSUB->n;

	pop(stack, line_n);
}