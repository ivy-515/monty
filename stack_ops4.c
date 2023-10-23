#include "monty.h"

/**
 * x_pchar - prints the char at the top of the stack
 * @stack: pointer to the stack
 * @line_num: line number
 */

void x_pchar(stack_t **stack, unsigned int line_num)
{
	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_num);
		fclose(gvar.file_ptr);
		free(gvar.args);
		free_list(stack);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_num);
		fclose(gvar.file_ptr);
		free(gvar.args);
		free_list(stack);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);
}

/**
 * x_pstr - prints the string starting at the top of the stack
 * @stack: pointer to the stack
 * @line_num: line number
 */

void x_pstr(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp;
	int n;

	(void)line_num;
	tmp = *stack;
	while (tmp)
	{
		n = tmp->n;
		if (n <= 0 || n > 127)
			break;
		printf("%c", n);
		tmp = tmp->next;
	}
	printf("\n");
}

