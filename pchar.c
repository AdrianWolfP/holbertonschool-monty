#include "monty.h"

/**
 * pchar - prints char at top of stack, if valid
 * @stack: stack, value of top of which to be printed
 * @ln: line number within monty instruction file
 */

void pchar(stack_t **stack, size_t ln)
{
	stack_t *top = NULL;

	if (!*stack)
	{
		fprintf(stderr, "L%lu: can't pchar, stack empty\n", ln);
		freeStack(stack);
		exit(EXIT_FAILURE);
	}

	top = *stack;

	if (top->n < 32 || top->n > 126)
	{
		fprintf(stderr, "L%lu: can't pchar, value out of range\n", ln);
		freeStack(stack);
		exit(EXIT_FAILURE);
	}

	putchar(top->n);
	putchar('\n');
}