#include "monty.h"

FILE *file = NULL;

/**
 * main- runs monty bytercode interpreter
 * @argc: ticker
 * @argv: argus
 * @pushNum: numbers push
 * Return: 0 (on success)
 */

int main(int argc, char **argv)
{
	void (*f)(stack_t **, unsigned int) = NULL;
	char *buffer = NULL, op[50] = {'\0'}, *token = NULL;
	char *pushNum = NULL;
	size_t bufsize = 0;
	stack_t *stack = NULL;
	unsigned int line_number = 1;

	if (argc != 2)
		fprintf(stderr, "%s\n", "USAGE: monty file"), exit(EXIT_FAILURE);
	file = fopen(argv[1], "r");
	if (file == NULL)
		fprintf(stderr, "ERROR: Can't open file %s\n", argv[1]), exit(EXIT_FAILURE);
	for (; getline(&buffer, &bufsize, file) != EOF; line_number++)
	{
		token = strtok((buffer), " \t\n");
		if (!token)
		{
			free(buffer), buffer = NULL;
			continue;
		}
		strcpy(op, token);
		f = get_func(&stack, line_number, op);
		if (!f)
			fprintf(stderr, "ERROR: malloc failed\n"), err();
		if (strcmp(op, "push") == 0)
		{
			token = strtok(NULL, " \t\n");
			if (!token)
			{
				free(buffer), buffer = NULL, free_stack(&stack);
				fprintf(stderr, "L%d: USAGE: push integer\n", line_number);
			}
			strcpy(pushNum, token);
		}
		free(buffer), buffer = NULL;
		f(&stack, line_number);
		if (strcmp(op, "push") == 0)
			pushOp(&stack, line_number, pushNum);
	}
	free(buffer), fclose(file), free_stack(&stack);
	return (EXIT_SUCCESS);
}

/**
 * get_func - finds function to use to execute the desired opcode
 * @stack: stack to operate on
 * @code: string used to find correct function
 * @l: line number of currect opcode
 * Return: pointer to desired function
 */
void (*get_func(stack_t **stack, int l, char *code))(stack_t **, unsigned int)
{
	instruction_t instruction[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
	};
	int i = 0;

	while (strcmp(code, instruction[i].opcode) != 0)
	{
		i++;
		if (i > 7)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", l, code);
			free_stack(stack);
			err();
		}
	}
	return (instruction[i].f);
}

/**
 * err - error handler
 */
void err(void)
{
	fclose(file);
	exit(EXIT_FAILURE);
}

/**
 * pushOp - new node gets a set value; pushes operation
 * @stack: linked list stack to push
 * @line_number: cerrect line number of bytecode
 * @pushNum: number added to new node
 */
void pushOp(stack_t **stack, unsigned int line_number, char *pushNum)
{
	if (strcmp(pushNum, "0") == 0)
		(*stack)->n = 0;
	if (strcmp(pushNum, "0") != 0)
	{
		(*stack)->n = atoi(pushNum);
		if ((*stack)->n == 0 || (pushNum[0] != '-' && (*stack)->n == -1))
		{
			fprintf(stderr, "ERROR: L%d: USAGE: push integer\n", line_number);
			free_stack(stack);
			err();
		}
	}
}

/**
 * free_stack - frees a linked list
 * @stack: stack to free
 */
void free_stack(stack_t **stack)
{
	if (!(stack) || !(*stack))
	{
		return;
	}
	free_stack(&((*stack)->next));
	free(*stack);
	*stack = NULL;
}
