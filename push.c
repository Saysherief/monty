#include "monty.h"

/**
 * push - pushes an integer on top of the stack
 * @stack: pointer to the head/top of the stack
 * @line_number: the line number the opcode exists on the monty file
 * Return: nothing
 */

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new = NULL;
	char *arg = strtok(NULL, " \n");

	if (arg == NULL || atoi(arg) == 0)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = atoi(arg);
	new->next = *stack;
	new->prev = NULL;
	if (*stack != NULL)
		(*stack)->prev = new;
	*stack = new;
}
