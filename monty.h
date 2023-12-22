#ifndef _MONTY_H_
#define _MONTY_H_

#define SPC_DELIM " \t\n\r"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>
#include <unistd.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instr_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */

typedef struct instr_s
{
	char *opcode;
	void (*f)(stack_t **stack, size_t line_n);
} instr_t;

/**
 * struct global_s - struct of data that needs to be shared across functions
 * @line: line read from file
 * @file: input file containing instructions on one or more lines
 */

typedef struct global_s
{
	char *line;
	FILE *file;
} global_t;

extern global_t share;

FILE *openFile(int argc, char *inFile);
ssize_t convey(stack_t **stack);
void opVerify(stack_t **stack, char *, size_t);
void freeStack(stack_t **stack);

/* operation opcodes */
void push(stack_t **stack, size_t line_n);
void pop(stack_t **stack, size_t line_n);
void swap(stack_t **stack, size_t line_n);
void rotl(stack_t **stack, size_t line_n);
void rotr(stack_t **stack, size_t line_n);

/* printer opcodes */
void pall(stack_t **stack, size_t line_n);
void pint(stack_t **stack, size_t line_n);
void pchar(stack_t **stack, size_t line_n);
void pstr(stack_t **stack, size_t line_n);

/* arithmetic opcodes */
void add(stack_t **stack, size_t line_n);
void sub(stack_t **stack, size_t line_n);
void diV(stack_t **stack, size_t line_n);
void mul(stack_t **stack, size_t line_n);
void mod(stack_t **stack, size_t line_n);

/* no operation opcode */
void nop(stack_t **stack, size_t line_n);

#endif