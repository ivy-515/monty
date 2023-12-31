#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

#define BUFFSIZE 1024

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_num);
} instruction_t;

/**
 * struct utils_s - struct to hold global variables
 * @args: array of strings to hold opcode and argument
 * @line_n: line number of the file
 * @file_ptr: pointer to the file
 * @queue: flag to indicate if queue is enabled
 * Description: struct to hold global variables
 * for stack, queues, LIFO, FIFO
 */

typedef struct utils_s
{
	char **args;
	unsigned int line_n;
	FILE *file_ptr;
	int queue;
} utils_t;

extern utils_t gvar;

void interpret_line(char *line, stack_t **stack);
void note_beg(stack_t **stack, const int n);
void note_end(stack_t **stack, const int n);
void x_push(stack_t **stack, unsigned int line_num);
void x_pall(stack_t **stack, unsigned int line_num);
void x_pint(stack_t **stack, unsigned int line_num);
void x_pop(stack_t **stack, unsigned int line_num);
void x_swap(stack_t **stack, unsigned int line_num);
void x_add(stack_t **stack, unsigned int line_num);
void x_nop(stack_t **stack, unsigned int line_num);
void x_sub(stack_t **stack, unsigned int line_num);
void x_div(stack_t **stack, unsigned int line_num);
void x_mul(stack_t **stack, unsigned int line_num);
void x_mod(stack_t **stack, unsigned int line_num);
void x_pchar(stack_t **stack, unsigned int line_num);
void x_pstr(stack_t **stack, unsigned int line_num);
void x_rotl(stack_t **stack, unsigned int line_num);
void x_rotr(stack_t **stack, unsigned int line_num);
void set_format(stack_t **stack, unsigned int line_num);
void free_list(stack_t **stack);

#endif

