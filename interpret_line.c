#include "monty.h"

/**
 * interpret_line - parses a line from a file
 * @line: line to parse
 * @stack: pointer to the stack
 */

void interpret_line(char *line, stack_t **stack)
{
	instruction_t opcodes[] = {
		{"push", x_push}, {"pall", x_pall},
		{"pint", x_pint}, {"pop", x_pop},
		{"swap", x_swap}, {"add", x_add},
		{"nop", x_nop}, {"sub", x_sub},
		{"div", x_div}, {"mul", x_mul},
		{"mod", x_mod}, {"pchar", x_pchar},
		{"pstr", x_pstr}, {"rotl", x_rotl},
		{"rotr", x_rotr}, {"stack", set_format},
		{"queue", set_format}, {NULL, NULL}
	};
	int i = 0;

	gvar.args[0] = strtok(line, " \n\t");
	if (gvar.args[0] && gvar.args[0][0] == '#')
		return;
	gvar.args[1] = strtok(NULL, " \n\t");
	if (gvar.args[0])
	{
		while (opcodes[i].opcode)
		{
			if (strcmp(opcodes[i].opcode, gvar.args[0]) == 0)
			{
				opcodes[i].f(stack, gvar.line_n);
				return;
			}
			i++;
		}
		fprintf(stderr, "L%d: unknown instruction %s\n", gvar.line_n, gvar.args[0]);
		fclose(gvar.file_ptr);
		free(gvar.args);
		free_list(stack);
		exit(EXIT_FAILURE);
	}
}

