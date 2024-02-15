#include "monty.h"

/**
 * pchar - s
 * @stack: Double linked list
 * @line_number: File line execution
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (free_stack(stack_t) ->n )
	{
		printf("%c\n", (*stack)->n);
		return;
	}
	fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
	free_stack(stack);
	exit(EXIT_FAILURE);
}