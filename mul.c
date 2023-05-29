#include "monty.h"

/**
 * mul - multiplies the 2nd top with the top element of the stack
 * @stack: pointer to the head/top of the stack
 * @line_number: the line number the opcode exists on the monty file
 * Return: nothing
 */

void mul(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	((*stack)->next)->n *= (*stack)->n;
	pop(stack, line_number);
}
