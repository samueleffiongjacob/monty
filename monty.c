#include "monty.h"
fclose_t _close = {NULL, NULL, NULL};
/**
 * main - a programm who implement the push and pall opcodes
 * pint, pop, swap, add, nop, sub, div, mul, mod, pchar, pstr
 * rotl, rotr
 * @argc: the number of argument
 * @argv: the arguments
 * Return: Always 0 (Success)
 */
int main(int argc, char *argv[])
{
	FILE *file;
	const char *file_from;
	stack_t *stack = NULL;
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"nop", nop},
		{"swap", swap},
		{"add", add},
		{"sub", sub},
		{"div", divi},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}};

	if (argc != 2)
		fprintf(stderr, "USAGE: monty file\n"), exit(EXIT_FAILURE);
	file_from = argv[1];
	file = fopen(file_from, "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_from);
		exit(EXIT_FAILURE);
	}
	_close.file = file;
	get_opcode(&stack, instructions, file);
	fclose(file);
	free_stack(stack);
	return (0);
}
