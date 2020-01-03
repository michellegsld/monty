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
	FILE *fin = fopen(argv[1], "r");
	char *str = NULL, *opcode_array[2];
	const char delim[4] = " \t\n";
	size_t str_len = 0, line_count = 0;

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
		line_count++;
		opcode_array[0] = strtok(str, delim); /* The opcode */
		opcode_array[1] = strtok(NULL, delim); /* ^ It's possible arg */
	}

	fclose(fin);

	return (0);
}
