#include "monty.h"


utils_t gvar;

/**
 * main - entry point
 * @argc: argument count
 * @argv: argument vector
 * Return: EXIT_SUCCESS or EXIT_FAILURE
*/

int main(int argc, char **argv)
{
	char line[BUFFSIZE];
	stack_t *stack = NULL;

	gvar.line_n = 0;
	gvar.args = NULL;
	gvar.queue = 0;
	if (argc == 2)
	{
		gvar.file_ptr = fopen(argv[1], "r");
		if (gvar.file_ptr == NULL)
		{
			fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
			exit(EXIT_FAILURE);
		}
		gvar.args = malloc(sizeof(char *) * 2);
		while (1)
		{
			if (fgets(line, BUFFSIZE, gvar.file_ptr) == NULL)
			{
				fclose(gvar.file_ptr);
				free(gvar.args);
				free_list(&stack);
				break;
			}
			gvar.line_n++;
			interpret_line(line, &stack);
		}
		return (EXIT_SUCCESS);
	}
	fprintf(stderr, "USAGE: monty file\n");
	return (EXIT_FAILURE);
}

