#include "monty.h"

/**
 * pint - print value at top of stack
 * @stack: stack, top of which is to be printed
 * @line_n: line number within monty instruction file
 */

void pint(stack_t **stack, size_t line_n)
{
	if (!stack || !*stack)
	{
		fprintf(stderr, "L%lu: can't pint, stack empty\n", line_n);
		freeStack(stack);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}