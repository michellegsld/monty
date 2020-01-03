#include "monty.h"

//This will most likely be removed as this is the purpose of pall
/**
 * print_stack - Prints every node of a stack
 * @h: The top of the stack
 */
//void print_stack(const stack_t *h)
//{
//	while (h)
//	{
//		printf("%d\n", h->n);
//		h = h->next;
//	}
//}

/**
 * stack_len - Counts the number of nodes in a stack
 * @h: The top of the stack
 *
 * Return: The number of nodes
 */
size_t stack_len(const stack_t *h)
{
	size_t count = 0;

	while (h)
	{
		count++;
		h = h->next;
	}

	return (count);
}
