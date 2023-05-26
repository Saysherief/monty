#include "monty.h"

/**
 * free_s - frees the stack
 * @stack: pointer to the head/top of the stack
 * Return: nothing
 */

void free_s(stack_t **stack)
{
	stack_t *current, *temp;

	current = *stack;
	while (current != NULL)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
	*stack = NULL;
}
