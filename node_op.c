#include "monty.h"

/**
 * note_beg - adds a new node at the beginning of a stack_t list
 * @stack: pointer to the stack
 * @n: value of the new node
 */

void note_beg(stack_t **stack, int n)
{
	stack_t *new, *tmp;

	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		fclose(gvar.file_ptr);
		free(gvar.args);
		free_list(stack);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	new->n = n;
	new->prev = NULL;
	new->next = NULL;
	if (!tmp)
	{
		*stack = new;
		return;
	}
	tmp->prev = new;
	new->next = tmp;
	*stack = new;
}

/**
 * note_end - adds a new node at the end of a stack_t list
 * @stack: pointer to the stack
 * @n: value of the new node
*/

void note_end(stack_t **stack, int n)
{
	stack_t *new, *tmp;

	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		fclose(gvar.file_ptr);
		free(gvar.args);
		free_list(stack);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	new->n = n;
	new->prev = NULL;
	new->next = NULL;
	if (!tmp)
	{
		*stack = new;
		return;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	new->prev = tmp;
}

