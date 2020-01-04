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
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * op_pint - Prints the value at the top of the stack
 * @head: The top of the stack
 * @line_num: The current line number within the file
 */
void op_pint(stack_t **head, unsigned int line_num)
{
	if (*head)
		printf("%d\n", (*head)->n);
	else
		err_mngr(1, line_num, NULL);
}

/**
 * op_pchar - Prints the char at the top of the stack
 * @head: The top of the stack
 * @line_num: The current line number within the file
 */
void op_pchar(stack_t **head, unsigned int line_num)
{
	int ch = (*head)->n;

	if (*head == NULL)
		err_mngr(6, line_num, NULL);

	if (ch >= 0 && ch <= 127)
		putchar(ch);
	else
		err_mngr(7, line_num, NULL);

	putchar('\n');
}

/**
 * op_pstr - Prints the string within the stack, starting at the top
 * @head: The top of the stack
 * @line_num: The current line number within the file
 */
void op_pstr(stack_t **head, unsigned int __attribute__((unused)) line_num)
{
	stack_t *current = *head;

	if (*head)
	{
		while (current)
		{
			if (current->n > 0 && current->n <= 127)
				putchar(current->n);
			else
				break;
			current = current->next;
		}
	}

	putchar('\n');
}
