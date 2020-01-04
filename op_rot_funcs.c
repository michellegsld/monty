#include "monty.h"

/**
 * op_rotl - Rotates the stack to the top
 * @head: The top of the stack
 * @line_num: The current line number within the file
 */
void op_rotl(stack_t **head, unsigned int __attribute__((unused)) line_num)
{
	stack_t *current = *head;

	if (*head && (*head)->next)
	{
		while (current->next)
			current = current->next;

		current->next = *head;
		*head = (*head)->next;
		(*head)->prev = NULL;
		current->next->next = NULL;
	}
}

/**
 * op_rotr - Rotates the stack to the bottom
 * @head: The top of the stack
 * @line_num: The current line number within the file
 */
void op_rotr(stack_t **head, unsigned int __attribute__((unused)) line_num)
{
	stack_t *current = *head;

	if (*head && (*head)->next)
	{
		while (current->next)
			current = current->next;

		(*head)->prev = current;
		current->next = *head;
		current->prev->next = NULL;
		current->prev = NULL;
		*head = current;
	}
}
