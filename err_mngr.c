#include "monty.h"

/**
 * err_mngr - Handles the different kinds of errors within the program
 * @flag: Will determine which error message to display
 * @line_num: Which line number the error was on
 * @str: Usually the opcode
 */
void err_mngr(int flag, unsigned int line_num, char *str)
{
	switch (flag)
	{
		case (0):	/* push fail */
			fprintf(stderr, "L%d: usage: push integer\n", line_num);
			break;
		case (1):	/* pint fail */
			fprintf(stderr, "L%d: can't pint, stack empty\n", line_num);
			break;
		case (2):	/* pop fail */
			fprintf(stderr, "L%d: can't pop an empty stack\n", line_num);
			break;
		case (3):	/* stack too short fail */
			fprintf(stderr, "L%d: can't %s, stack too short\n", line_num, str);
			break;
		case (4):	/* by zero fail */
			fprintf(stderr, "L%d: division by zero\n", line_num);
			break;
		case (5):	/* malloc fail */
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case (6):	/* pchar stack fail */
			fprintf(stderr, "L%d: can't pchar, stack empty\n", line_num);
			break;
		case (7):	/* pchar range fail */
			fprintf(stderr, "L%d: can't pchar, value out of range\n", line_num);
			break;
		case (8):	/* number of arguments fail */
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case(9): /* File open fail */
			fprintf(stderr, "Error: Can't open file %s\n", str);
			break;
		case(10):
			fprintf(stderr, "L%d: unknown instruction %s\n", line_num, str);
			break;
		default:
			break;
	}
	exit(EXIT_FAILURE);
}