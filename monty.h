#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* stack_help.c */
size_t print_stack(const stack_t *h);
size_t stack_len(const stack_t *h);

/* op_math_funcs.c */
void op_add(stack_t *head, unsigned int line_num);
void op_sub(stack_t *head, unsigned int line_num);
void op_mul(stack_t *head, unsigned int line_num);
void op_div(stack_t *head, unsigned int line_num);
void op_mod(stack_t *head, unsigned int line_num);

#endif
