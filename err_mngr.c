#include "monty.h"

/**
 * err_mngr_cont - Handles more different kinds of errors within the program
 * @flag: Will determine which error message to display
 * @line_num: Which line number the error was on
 * @str: Either NULL or the unknown instruction
 */
void err_mngr_cont(int flag, unsigned int line_num, char *str)
{
	switch (flag)
	{
		case(9):
			fprintf(stderr, "L%d: unknown instruction %s\n", line_num, str);
			break;
		case (10):	/* add fail */
			fprintf(stderr, "L%d: can't add, stack too short\n", line_num);
			break;
		case (11):	/* sub fail */
			fprintf(stderr, "L%d: can't sub, stack too short\n", line_num);
			break;
		case (12):	/* mul fail */
			fprintf(stderr, "L%d: can't mul, stack too short\n", line_num);
			break;
		case (13):	/* div fail */
			fprintf(stderr, "L%d: can't div, stack too short\n", line_num);
			break;
		case (14):	/* mod fail */
			fprintf(stderr, "L%d: can't mod, stack too short\n", line_num);
			break;
		case (15):	/* malloc fail */
			fprintf(stderr, "L%d: can't pchar, stack empty\n", line_num);
			break;
		default:
			break;
	}
	free_stack(p_head);
	free(get_str);
	fclose(fin);
	exit(EXIT_FAILURE);
}

/**
 * err_mngr - Handles the different kinds of errors within the program
 * @flag: Will determine which error message to display
 * @line_num: Which line number the error was on
 * @str: Either NULL or the file that failed to open
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
		case (3):	/* swap fail */
			fprintf(stderr, "L%d: can't swap, stack too short\n", line_num);
			break;
		case (4):	/* by zero fail */
			fprintf(stderr, "L%d: division by zero\n", line_num);
			break;
		case (5):	/* malloc fail */
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case (6):	/* pchar range fail */
			fprintf(stderr, "L%d: can't pchar, value out of range\n", line_num);
			break;
		case (7):	/* number of arguments fail */
			fprintf(stderr, "USAGE: monty file\n");
			exit(EXIT_FAILURE);
			break;
		case(8): /* File open fail */
			fprintf(stderr, "Error: Can't open file %s\n", str);
			exit(EXIT_FAILURE);
			break;
		default:
			err_mngr_cont(flag, line_num, str);
	}
	free_stack(p_head);
	free(get_str);
	fclose(fin);
	exit(EXIT_FAILURE);
}
