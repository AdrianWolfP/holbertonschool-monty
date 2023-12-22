#include "monty.h"

/**
 * swap - swaps locations of top 2 elements in stack
 * @stack: stack, top 2 elements of which to be swapped
 * @line_n: line number within monty instruction file
 */

void swap(stack_t **stack, size_t line_n)
{
	stack_t *oldtop = NULL, *newtop = NULL;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%lu: can't swap, stack too short\n", line_n);
		freeStack(stack);
		exit(EXIT_FAILURE);
	}

	oldtop = *stack;
	newtop = oldtop->next;
	oldtop->next = newtop->next;
	newtop->next = oldtop;
	oldtop->prev = newtop;
	newtop->prev = NULL;

	*stack = newtop;
}