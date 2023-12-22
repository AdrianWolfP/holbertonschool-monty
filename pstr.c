#include "monty.h"

/**
 * pstr - prints string beginning at top of stack, if valid
 * @stack: stack, value of top of which to be printed
 * @line_n: line number within monty instruction file
 */

void pstr(stack_t **stack, size_t line_n)
{
	stack_t *top = NULL;

	(void)line_n;

	if (!*stack)
	{
		putchar('\n');
		return;
	}

	for (top = *stack; top; top = top->next)
	{
		if (top->n < 32 || top->n > 126)
			break;
		putchar(top->n);
	}

	putchar('\n');
}