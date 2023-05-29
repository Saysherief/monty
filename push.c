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

	if (arg == NULL || !is_int(arg))
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

/**
 * is_int - checks if the string is an integer
 * @s: a pointer to the string /the first char on the string
 * Return: 1 if integer and 0 if not
 */
int is_int(char *s)
{
	int i = 0;

	if (s[0] == '-' || s[0] == '+')
		i++;
	while (s[i] != '\0')
	{
		if (!isdigit(s[i]))
			return (0);/*not int*/
		i++;
	}
	return (1);
}
