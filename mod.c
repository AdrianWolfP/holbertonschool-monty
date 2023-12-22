#include "monty.h"

/**
 * mod - modulo top 2 node values in stack, second node takes result, pop top
 * @stack: stack, division of top 2 elements of which to find the remainder
 * @line_n: line number within monty instruction file
 */

void mod(stack_t **stack, size_t line_n)
{
	stack_t *oldtopMOD = NULL, *newtopRES = NULL;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%lu: can't mod, stack too short\n", line_n);
		freeStack(stack);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%lu: division by zero\n", line_n);
		freeStack(stack);
		exit(EXIT_FAILURE);
	}

	oldtopMOD = *stack;
	newtopRES = oldtopMOD->next;
	newtopRES->n %= oldtopMOD->n;

	pop(stack, line_n);
}