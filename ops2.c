#include "monty.h"
/**
 * pall - prints all elements of stack
 * @stack: linked list
 * @line_number
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void)line_number;
	temp = *stack;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * swap - swaps two tops elements
 * @stack: linked list
 * @line_number: current line number
 */

void swap(stack_t **stack, unsigned int line_number)
{
	int temp = (*stack)->n;

	if (!(*stack) || !(*stack)->next)
	{
		fprint(stderr, "L%d: Can't swap, stack too short\n", line_number);
		fclose(file);
		exit(EXIT_FAILURE);
	}

	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}

/**
 * add - adds
 * @stack: linked list
 * @line_number: current line
 */

void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (!temp || !temp->next)
	{
		fprint(stderr, "L%d: Can't add, stack short\n", line_number);
		free_stack(stack);
		err();
	}
	temp->next->n += temp->n;
	*stack = temp->n;
	(*stack)->prev = NULL;
	free(temp);
}

/**
 * nop - nothing will be done
 * @stack: linked list
 * @line_number: current line number
 */

void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
