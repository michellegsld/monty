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
    FILE *fin = fopen(argv[1],"r");

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

    if (fin == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

	printf("The argument count amount was 2 and the file \"%s\" could be opened.\n", argv[1]);

    fclose(fin);

    return 0;
}
