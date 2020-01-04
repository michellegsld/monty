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
	stack_t *head = NULL;
	void (*func)(stack_t **stack, unsigned int line_number);
	FILE *fin = fopen(argv[1], "r"); /* Open file to read */
	char *str = NULL, *opcode_array[2];
	const char delim[3] = " \t\n";
	size_t str_len = 0, lc = 0;

	if (argc != 2) /* Check if amount of arguments is correct */
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	if (fin == NULL) /* If file was able to be opened */
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (getline(&str, &str_len, fin) != -1) /*Read each file line */
	{
		lc++;fsdafsddsfa
		opcode_array[0] = strtok(str, delim); /* The opcode */
		opcode_array[1] = strtok(NULL, delim); /* ^ It's possible arg */
		push_tok = opcode_array[1]; /* The extern variable pointer */
		if (opcode_array[0] != NULL && opcode_array[0][0] != '#')
		{
			func = get_opcode_func(opcode_array[0]);
			if (func == NULL)
			{
				fprintf(stderr, "L%ld: unknown instruction %s\n", lc, opcode_array[0]);
				exit(EXIT_FAILURE);
			else
				func(&head, lc);
		}
	}
	fclose(fin); /* Close file */
	free(str);
	free_stack(head);
	return (0);
}
