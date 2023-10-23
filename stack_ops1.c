#include "monty.h"

/**
 * x_add - adds the top two elements of the stack
 * @stack: pointer to the stack
 * @line_num: line number
 */

void x_add(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp;
	int sum;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_num);
		fclose(gvar.file_ptr);
		free(gvar.args);
		free_list(stack);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	sum = tmp->n + tmp->next->n;
	tmp->next->n = sum;
	*stack = (*stack)->next;
	free(tmp);
}

/**
 * x_mul - multiplies the second top element of the stack with the top element
 * @stack: pointer to the stack
 * @line_um: line number
*/

void x_mul(stack_t **stack, unsigned int line_um)
{
	int n;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_um);
		fclose(gvar.file_ptr);
		free(gvar.args);
		free_list(stack);
		exit(EXIT_FAILURE);
	}
	n = (*stack)->n;
	x_pop(stack, line_um);
	(*stack)->n *= n;
}

/**
 * x_nop - does nothing
 * @stack: pointer to the stack
 * @line_num: line number
*/

void x_nop(stack_t **stack, unsigned int line_num)
{
	(void)stack;
	(void)line_num;
}

/**
 * x_pall - prints all the values on the stack, starting from the top
 * @stack: pointer to the stack
 * @line_num: line number
 */

void x_pall(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp;

	(void)line_num;
	tmp = *stack;
	if (!tmp)
		return;
	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * x_pint - prints the value at the top of the stack
 * @stack: pointer to the stack
 * @line_num: line number
 */

void x_pint(stack_t **stack, unsigned int line_num)
{
	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_num);
		fclose(gvar.file_ptr);
		free(gvar.args);
		free_list(stack);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
