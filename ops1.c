#include "monty.h"
/**
 * push - adds an element to a stack
 * @stack: linked list
 * @line_number: current line number
 */

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *newNode;

	newNode = malloc(sizeof(stack_t));

	if (!newNode)
	{
		fprint(stderr, "ERROR: malloc failed\n");
		free_stack(stack);
		err();
	}

	(void)line_number;
	
	if (*stack)
	(*stack)->prev = newNode;

	newNode->prev = NULL;
	newNode->next = *stack;
	newNode->n = 0;
	*stack = newNode;
}

/**
 * pop - removes first element of the stack
 * @stack: linekd list
 * @line_number: current line number
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	temp = *stack;
	if (!(*stack))
	{
		fprint(stderr, "L%d: Can't pop an empty stack\n", line_number);
		fclose(file);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	*stack = temp->next;
	if (*stack)
		(*stack)->prev = NULL;
	free(temp);
}

/**
 * pint - prints value in first node
 * @stack: linked list
 * @line_number: current line number
 */

void pint(stack_t **stack, unsigned int line_number);
{
	if (!(*stack))
	{
		fprint(stderr, "L%d: Can't pint, stack empty\n", line_number);
		fclose(file);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
