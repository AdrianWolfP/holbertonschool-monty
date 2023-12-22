#include "monty.h"

/**
 * rotl - rotates top element of stack to bottom
 * @stack: stack, top element of which to be rotated to stack bottom
 * @line_n: line number within monty instruction file
 */

void rotl(stack_t **stack, size_t line_n)
{
	stack_t *iterant = NULL, *newtop = NULL, *oldtop = NULL;

	(void)line_n;

	if (!*stack || !(*stack)->next)
		return;

	oldtop = *stack;
	newtop = oldtop->next;
	newtop->prev = NULL;

	for (iterant = oldtop; iterant->next; iterant = iterant->next)
		;

	iterant->next = oldtop;
	oldtop->next = NULL;
	oldtop->prev = iterant;

	*stack = newtop;
}