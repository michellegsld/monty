#include "monty.h"

/**
 * op_pall - Prints all values on the stack
 * @head: The top of the stack
 * @line_num: The current line number within the file
 */
void op_pall(stack_t **head, unsigned int __attribute__((unused)) line_num)
{
	stack_t *current = *head;

	while (current)
	{
		printf("%d\n", (current)->n);
		(current) = (current)->next;
	}
}

//Functions to add to this file:
//	- pint : Print the value at the top of the stack
//	- pchar : Prints the char at the top of the stack
//	- pstr : Prints the string within the stack, starting at the top