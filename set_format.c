#include "monty.h"

/**
 * set_format - sets the format of the data to a stack (LIFO) or queue (FIFO)
 * @stack: pointer to the stack
 * @line_num: line number
 * Return: 0 on success, 1 on failure
*/

void set_format(stack_t **stack, unsigned int line_num)
{
	(void)stack;
	(void)line_num;
	if (strcmp(gvar.args[0], "stack") == 0)
		gvar.queue = 0;
	else if (strcmp(gvar.args[0], "queue") == 0)
		gvar.queue = 1;
}

