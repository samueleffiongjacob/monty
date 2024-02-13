#ifndef __monty__
#define __monty__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/syscall.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Alx project
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
 * for stack, queues, LIFO, FIFO Alx project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_num);
} instruction_t;

/**
 * struct info_s - info to access
 * @monty_file: file
 * @line: line
 * @stack: stack
 * @line_number: line number
 * @queue_status: off by default
 * Description: global struct with info
 */
 typedef struct info_s
{
	FILE *monty_file;
	char *line;
	stack_t *stack;
	unsigned int line_number;
	_Bool queue_status;
} info_t;

extern info_t info;

void pint(stack_t **stack, unsigned int line_num);
void free_stack(stack_t *head);
void garbage_collection(void);
void validate_and_open(int argc, char *argv);
void read_lines(void);
void init_info(void);
int pushint(char *list, int ln);
int _strcmp(char *opcode, char *list);
void add(stack_t **stack, unsigned int line_num);
void swap(stack_t **stack, unsigned int line_num);
void pop(stack_t **stack, unsigned int line_num);
void push(stack_t **stack, unsigned int line_number, int n);
void pall(stack_t **stack, unsigned int line_num);
void execute(char *string[], stack_t *stack);
int nlfind(char *list);
void free_list(char *a[]);
int combfind(char *list, int ln);
int get_op_func(char *str, stack_t **stack, int line_number)


#endif