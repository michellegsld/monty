#include "monty.h"

/**
 * op_push - Pushes an element to the stack
 * @head: The top of the stack
 * @line_num: The current line number within the file
 */
void op_push(stack_t **head, unsigned int line_num)
{
	stack_t *current = *head;
	stack_t *new = NULL;
	int num;
	unsigned int i = 0;

	if (push_tok == NULL)
		err_mngr(0, line_num, NULL);
	while (i < strlen(push_tok))
	{
		if (!isdigit(push_tok[i]))
			err_mngr(0, line_num, NULL);
		i++;
	}
	num = atoi(push_tok);
	new = malloc(sizeof(stack_t));
	if (new == NULL)
		err_mngr(5, line_num, NULL);
	new->n = num;
	if (sorq == 0) /* If this is a stack */
	{
		new->prev = NULL;
		new->next = *head;
		if (*head)
			(*head)->prev = new;
		*head = new;
		return;
	}
	new->prev = *head;	/* Else this was a queue */
	new->next = NULL;
	if (*head)
	{
		while (current->next)
		{
			current = current->next;
			new->prev = current;
		}
		current->next = new;
	}
	else
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
		err_mngr(2, line_num, NULL);

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
		err_mngr(3, line_num, "swap");

	tmp = (*head)->n;
	(*head)->n = (*head)->next->n;
	(*head)->next->n = tmp;
}
