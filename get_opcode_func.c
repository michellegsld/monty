#include "monty.h"

/**
 * *get_opcode_func - Checks if the string is a valid opcode and calls it if is
 * @op: The string to check if is an opcode
 *
 * Return: The opcode's function or NULL
 */
void (*get_opcode_func(char *op))(stack_t **, unsigned int)
{
	instruction_t opcodes[] = {
		{"push", op_push},
		{"pall", op_pall},
		{"pint", op_pint},
		{"pop", op_pop},
		{"swap", op_swap},
		{"add", op_add},
		{"sub", op_sub},
		{"mul", op_mul},
		{"div", op_div},
		{"mod", op_mod},
		{"pchar", op_pchar},
		{"pstr", op_pstr},
		{"rotl", op_rotl},
		{"rotr", op_rotr},
		{NULL, NULL}
	};
	size_t i = 0;

	if (strcmp(op, "nop") == 0)
		donot = 1;
	else if (strcmp(op, "stack") == 0)
	{
		donot = 1;
		sorq = 0;
	}
	else if (strcmp(op, "queue") == 0)
	{
		donot = 1;
		sorq = 1;
	}
	else
	{
		while (opcodes[i].opcode != NULL)
		{
			if (strcmp(opcodes[i].opcode, op) == 0)
			{
				donot = 0;
				return (opcodes[i].f);
			}
			i++;
		}
	}
	return (NULL);
}
