#include "monty.h"

/**
 * main - Takes file as input and runs each line for the monty program
 * @argc: Argument count, the amount of arguments
 * @argv: Argument vector, an array of with each argument
 *
 * Return: 0 on program success
 */
int main(int argc, char *argv[])
{
	void (*func)(stack_t **stack, unsigned int line_number);
	char *opcode_array[2];
	stack_t *head = NULL;
	const char delim[3] = " \t\n";
	size_t str_len = 0, lc = 0;

	get_str = NULL;
	sorq = 0;
	fin = fopen(argv[1], "r"); /* Open file to read */

	if (argc != 2) /* Check if amount of arguments is correct */
		err_mngr(7, lc, NULL);

	if (fin == NULL) /* If file wasn't able to be opened */
		err_mngr(8, lc, argv[1]);

	while (getline(&get_str, &str_len, fin) != -1) /*Read each file line */
	{
		lc++;
		p_head = head;
		donot = 0; /* Reset donot variable */
		opcode_array[0] = strtok(get_str, delim); /* The opcode */
		opcode_array[1] = strtok(NULL, delim); /* ^ It's possible arg */
		push_tok = opcode_array[1]; /* The extern variable pointer */
		if (opcode_array[0] != NULL && opcode_array[0][0] != '#')
		{
			func = get_opcode_func(opcode_array[0]);
			if (func == NULL && donot == 0)
				err_mngr(9, lc, opcode_array[0]);
			else if (donot == 0)
				func(&head, lc);
		}
	}
	fclose(fin); /* Close file */
	free(get_str);
	free_stack(p_head);
	return (0);
}
