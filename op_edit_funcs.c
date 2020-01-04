#include "monty.h"

/**
 * op_push - Pushs an element to the stack
 * @head: The top of the stack
 * @line_num: The current line number within the file
 */
void op_push(stack_t **head, unsigned int line_num)
{
	stack_t *new;
	int num;

	if (push_tok != NULL)
		num = atoi(push_tok);

	if (push_tok == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_num);
		exit(EXIT_FAILURE);
	}

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new->n = num;
	new->prev = NULL;
	new->next = *head;

	if (*head)
		(*head)->prev = new;

	*head = new;
}

//Functions to add to this file:
//	- pop : Removes the top element of the stack
//	- swap : Swaps the top two elements of the stack