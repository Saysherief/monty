#include "monty.h"

/**
 * pint - prints the value at the top of the stack, followed by a new line
 * @stack: pointer to the head/top of the stack
 * @line_number: the line number the opcode exists on the monty file
 * Return: nothing
 */

void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
