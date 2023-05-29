#include "monty.h"

/**
 * mod - remainder of the division of 2nd top by the top element of the stack
 * @stack: pointer to the head/top of the stack
 * @line_number: the line number the opcode exists on the monty file
 * Return: nothing
 */

void mod(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (((*stack)->n) == 0)
	{
		fprintf(stderr, "L%u\: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	((*stack)->next)->n %= (*stack)->n;
	pop(stack, line_number);
}
