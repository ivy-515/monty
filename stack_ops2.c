#include "monty.h"

/**
 * x_mod - computes the rest of the division of the second top element
 * of the stack by the top element of the stack
 * @stack: pointer to the stack
 * @line_num: line number
*/

void x_mod(stack_t **stack, unsigned int line_num)
{
	int n;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_num);
		fclose(gvar.file_ptr);
		free(gvar.args);
		free_list(stack);
		exit(EXIT_FAILURE);
	}
	n = (*stack)->n;
	if (n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_num);
		fclose(gvar.file_ptr);
		free(gvar.args);
		free_list(stack);
		exit(EXIT_FAILURE);
	}
	x_pop(stack, line_num);
	(*stack)->n %= n;
}

/**
 * x_div - divides the second top element of the stack by the top element
 * @stack: pointer to the stack
 * @line_num: line number
*/

void x_div(stack_t **stack, unsigned int line_num)
{
	int n;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_num);
		fclose(gvar.file_ptr);
		free(gvar.args);
		free_list(stack);
		exit(EXIT_FAILURE);
	}
	n = (*stack)->n;
	if (n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_num);
		fclose(gvar.file_ptr);
		free(gvar.args);
		free_list(stack);
		exit(EXIT_FAILURE);
	}
	x_pop(stack, line_num);
	(*stack)->n /= n;
}

/**
 * x_pop - removes the top element of the stack
 * @stack: pointer to the stack
 * @line_num: line number
 */

void x_pop(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp;

	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_num);
		fclose(gvar.file_ptr);
		free(gvar.args);
		free_list(stack);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	*stack = (*stack)->next;
	free(tmp);
}

/**
 * isNumber - checks if a string is a number
 * @str: string to check
 * Return: 1 if true, 0 if false
 */

int isNumber(const char *str)
{
	if (!str || *str == '\0')
		return (0);
	if (*str == '-')
		str++;
	while (*str)
	{
		if (!isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

/**
 * x_push - pushes an element to the stack
 * @stack: pointer to the stack
 * @line_num: line number
 */

void x_push(stack_t **stack, unsigned int line_num)
{
	int n;

	if (!gvar.args[1] || !isNumber(gvar.args[1]))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_num);
		fclose(gvar.file_ptr);
		free(gvar.args);
		free_list(stack);
		exit(EXIT_FAILURE);
	}
	n = atoi(gvar.args[1]);
	if (gvar.queue)
		note_end(stack, n);
	else
		note_beg(stack, n);
}
