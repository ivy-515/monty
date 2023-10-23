#include "monty.h"

/**
 * x_sub - subtracts the top element of the stack from the second top element
 * @stack: pointer to the stack
 * @line_num: line number
*/

void x_sub(stack_t **stack, unsigned int line_num)
{
	int n;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_num);
		fclose(gvar.file_ptr);
		free(gvar.args);
		free_list(stack);
		exit(EXIT_FAILURE);
	}
	n = (*stack)->n;
	x_pop(stack, line_num);
	(*stack)->n -= n;
}

/**
 * x_rotl - rotates the stack to the top
 * @stack: pointer to the stack
 * @line_num: line number
 */

void x_rotl(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp, *tmp2;

	(void)line_num;
	if (!*stack || !(*stack)->next)
		return;
	tmp = *stack;
	tmp2 = (*stack)->next;
	tmp2->prev = NULL;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = *stack;
	(*stack)->prev = tmp;
	(*stack)->next = NULL;
	*stack = tmp2;
}

/**
 * x_rotr - rotates the stack to the bottom
 * @stack: pointer to the stack
 * @line_num: line number
 */

void x_rotr(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp, *tmp2;

	(void)line_num;
	if (!*stack || !(*stack)->next)
		return;
	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	tmp2 = tmp->prev;
	tmp2->next = NULL;
	tmp->prev = NULL;
	tmp->next = *stack;
	(*stack)->prev = tmp;
	*stack = tmp;
}

/**
 * x_swap - swaps the top two elements of the stack
 * @stack: pointer to the stack
 * @line_num: line number
 */

void x_swap(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp;
	int tmp_n;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_num);
		fclose(gvar.file_ptr);
		free(gvar.args);
		free_list(stack);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	tmp_n = tmp->n;
	tmp->n = tmp->next->n;
	tmp->next->n = tmp_n;
}
