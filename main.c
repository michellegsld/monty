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
	char *str_buf = NULL;
    size_t line_count = 0;
    size_t str_buf_len = 0;
    //ssize_t str_len = 0;

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

	//str_len = getline(&str_buf, &str_buf_len, fin);

    //while (str_len >= 0)
    //{
    //    line_count++;
    //   printf("Line number: %d, Line contents: %s\n", str_buf_len, str_buf);
    //    str_len = getline(&str_buf, &str_buf_len, fin);
    //}

	while(getline(&str_buf, &str_buf_len, fin) != -1)
	{
        line_count++;
		printf("This is the line: \"%s\".\n", str_buf);
	}

	printf("The argument count amount was 2 and the file \"%s\" could be opened.\n", argv[1]);

	fclose(fin);

	return 0;
}
