#include "monty.h"

/**
 * free_list - frees a stack
 * @stack: pointer to the stack
 */

void free_list(stack_t **stack)
{
	stack_t *tmp;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

