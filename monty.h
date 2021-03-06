#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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

/* Extern Variable */
extern FILE *fin;	/* The pointer to the file to open and read */
FILE *fin;
extern char *get_str; /* The pointer within getline */
char *get_str;
extern char *push_tok;	/* Contains arg for push */
char *push_tok;
extern int sorq;	/* Checks if complete a stack or queue */
int sorq;
extern int donot;	/* A flag if the opcode sent in should do nothing */
int donot;
extern stack_t *p_head; /* The pointer to the start of the stack */
stack_t *p_head;

/* get_opcode_func.c */
void (*get_opcode_func(char *op))(stack_t **, unsigned int);

/* op_edit_funcs.c */
void op_push(stack_t **head, unsigned int line_num);
void op_pop(stack_t **head, unsigned int line_num);
void op_swap(stack_t **head, unsigned int line_num);

/* op_print_funcs.c */
void op_pall(stack_t **head, unsigned int line_num);
void op_pint(stack_t **head, unsigned int line_num);
void op_pchar(stack_t **head, unsigned int line_num);
void op_pstr(stack_t **head, unsigned int line_num);

/* op_math_funcs.c */
void op_add(stack_t **head, unsigned int line_num);
void op_sub(stack_t **head, unsigned int line_num);
void op_mul(stack_t **head, unsigned int line_num);
void op_div(stack_t **head, unsigned int line_num);
void op_mod(stack_t **head, unsigned int line_num);

/* op_rot_funcs.c */
void op_rotl(stack_t **head, unsigned int line_num);
void op_rotr(stack_t **head, unsigned int line_num);

/* err_mngr.c */
void err_mngr(int flag, unsigned int line_num, char *str);

/* stack_help.c */
void free_stack(stack_t *head);
size_t stack_len(stack_t *h);

#endif
