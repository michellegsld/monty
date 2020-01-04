#include "monty.h"

/**
 * op_add - Adds the top 2 elements of the stack
 * @head: The top of the stack
 * @line_num: The current line number within the file
 */
void op_add(stack_t **head, unsigned int line_num)
{
	if (stack_len(*head) < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short", line_num);
		exit(EXIT_FAILURE);
	}
	(*head)->next->n = (*head)->next->n + (*head)->n;
	*head = (*head)->next;
	free((*head)->prev);
	(*head)->prev = NULL;
}

 /**
 * op_sub - Subtracts the top element of the stack from the 2nd one
 * @head: The top of the stack
 * @line_num: The current line number within the file
 */
void op_sub(stack_t **head, unsigned int line_num)
{
	if (stack_len(*head) < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	(*head)->next->n = (*head)->next->n - (*head)->n;
	*head = (*head)->next;
	free((*head)->prev);
	(*head)->prev = NULL;
}

 /**
 * op_mul - Multiplies the top 2 elements of the stack
 * @head: The top of the stack
 * @line_num: The current line number within the file
 */
void op_mul(stack_t **head, unsigned int line_num)
{
	if (stack_len(*head) < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

	(*head)->next->n = (*head)->next->n * (*head)->n;
	*head = (*head)->next;
	free((*head)->prev);
	(*head)->prev = NULL;
}

 /**
 * op_div - Divides the 2nd element of the stack by the first
 * @head: The top of the stack
 * @line_num: The current line number within the file
 */
void op_div(stack_t **head, unsigned int line_num)
{
	if (stack_len(*head) < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	if ((*head)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_num);
		exit(EXIT_FAILURE);
	}
	(*head)->next->n = (*head)->next->n / (*head)->n;
	*head = (*head)->next;
	free((*head)->prev);
	(*head)->prev = NULL;
}

/**
 * op_mod - Gets remainder  the 2nd element divided by the 1st in the stack
 * @head: The top of the stack
 * @line_num: The current line number within the file
 */
void op_mod(stack_t **head, unsigned int line_num)
{
	if (stack_len(*head) < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	if ((*head)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_num);
		exit(EXIT_FAILURE);
	}
	(*head)->next->n = (*head)->next->n % (*head)->n;
	*head = (*head)->next;
	free((*head)->prev);
	(*head)->prev = NULL;
}