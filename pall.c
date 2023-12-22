#include "monty.h"

/**
 * pall - print all elements of the stack as they are
 * @stack: stack, elements of which are to be printed
 * @line_n: line number within monty instruction file
 */

void pall(stack_t **stack, size_t line_n)
{
	stack_t *pos = NULL;

	(void)line_n;

	for (pos = *stack; pos; pos = pos->next)
		printf("%d\n", pos->n);
}