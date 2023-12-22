#include "monty.h"

/**
 * mul - multiply top 2 node values in stack, second node takes result, pop top
 * @stack: stack, top 2 elements of which to be multiplied
 * @line_n: line number within monty instruction file
 */

void mul(stack_t **stack, size_t line_n)
{
	stack_t *oldtopMUL = NULL, *newtopRES = NULL;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%lu: can't mul, stack too short\n", line_n);
		freeStack(stack);
		exit(EXIT_FAILURE);
	}

	oldtopMUL = *stack;
	newtopRES = oldtopMUL->next;
	newtopRES->n *= oldtopMUL->n;

	pop(stack, line_n);
}