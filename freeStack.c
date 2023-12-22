#include "monty.h"

/**
 * freeStack - frees memory allocated for stack
 * @stack: stack to be freed
 */

void freeStack(stack_t **stack)
{
	stack_t *top = NULL, *pos = NULL;

	if (share.line)
		free(share.line);
	if (share.file)
		fclose(share.file);

	for (top = *stack; top;)
		pos = top, top = top->next, free(pos);

	*stack = NULL;
}