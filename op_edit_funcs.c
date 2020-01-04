#include "monty.h"

/**
 * op_push - Pushs an element to the stack
 * @head: The top of the stack
 * @line_num: The current line number within the file
 */
void op_push(stack_t **head, unsigned int line_num)
{
	stack_t *new = malloc(sizeof(stack_t));
	int num;
	unsigned int i = 0;

	if (push_tok != NULL)
		num = atoi(push_tok);

	if (push_tok == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_num);
		exit(EXIT_FAILURE);
	}

	while (i < strlen(push_tok))
	{
		if (!isdigit(push_tok[i]))
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_num);
			exit(EXIT_FAILURE);
		}
		i++;
	}

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

/**
 * op_pop - Removes the top element of the stack
 * @head: The top of the stack
 * @line_num: The current line number within the file
 */
void op_pop(stack_t **head, unsigned int line_num)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_num);
		exit(EXIT_FAILURE);
	}

	if ((*head)->next)
	{
		*head = (*head)->next;
		free((*head)->prev);
		(*head)->prev = NULL;
	}
	else
	{
		free(*head);
		*head = NULL;
	}
}

/**
 * op_swap - Swaps the top two elements of the stack
 * @head: The top of the stack
 * @line_num: The current line number within the file
 */
void op_swap(stack_t **head, unsigned int line_num)
{
	int tmp;

	if (stack_len(*head) < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

	tmp = (*head)->n;
	(*head)->n = (*head)->next->n;
	(*head)->next->n = tmp;
}
