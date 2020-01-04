#include "monty.h"

/**
 * get_opcode_func - Checks if the string is a valid opcode and calls it if is
 * @op: The string to check if is an opcode
 */
void (*get_opcode_func(char *op))(stack_t **, unsigned int)
{
	instruction_t opcodes[] = {
		{"push", op_push},
		{"pall", op_pall},
		{"add", op_add},
		{"sub", op_sub},
		{"mul", op_mul},
		{"div", op_div},
		{"mod", op_mod},
		{NULL, NULL}
	};
	size_t i = 0;

	while (opcodes[i].opcode != NULL)
	{
		if (strcmp(opcodes[i].opcode, op) == 0)
			return (opcodes[i].f);
		i++;
	}
	return (NULL);
}