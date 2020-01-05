#include "monty.h"

/**
 * free_stack - Frees a the stack
 * @head: The first node in the list
 */
void free_stack(stack_t *head)
{
	if (head)
	{
		free_stack(head->next);
		free(head);
	}
}

/**
 * stack_len - Counts the number of nodes in a stack
 * @h: The top of the stack
 *
 * Return: The number of nodes
 */
size_t stack_len(stack_t *h)
{
	stack_t *current = h;
	size_t count = 0;

	while (current)
	{
		count++;
		current = current->next;
	}

	return (count);
}
