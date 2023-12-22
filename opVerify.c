#include "monty.h"

/**
 * opVerify - manages commands & calls correlating function upon matching input
 * @stack: stack upon which operations are expected to be performed
 * @cmd: command to be verified against list of valid instructions
 * @line_n: line number within monty instruction file
 */

void opVerify(stack_t **stack, char *cmd, size_t line_n)
{
	instr_t ops[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", diV},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};
	int i = 0, sz = 0;

	if (cmd)
		for (i = 0, sz = (sizeof(ops) / sizeof(instr_t));
		     i < (sz - 1);
		     i++)
			if (!strcmp(ops[i].opcode, cmd))
			{
				ops[i].f(stack, line_n);
				return;
			}

	if (cmd[0] != '#')
	{
		fprintf(stderr, "L%lu: unknown instruction %s\n", line_n, cmd);
		freeStack(stack);
		exit(EXIT_FAILURE);
	}
}