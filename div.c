#include "monty.h"

/**
 * divi - divide the top two elements of the stack
 * @stack: Double linked list
 * @line_number: File line counter
 */
void divi(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp1;
	int division = 0;

	if (*stack == NULL || ((*stack)->prev == NULL && (*stack)->next == NULL))
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_stack(*stack);
		fclose(_close.file);
		free(_close.tmp);
		exit(EXIT_FAILURE);
	}
	tmp1 = *stack;
	division = tmp1->n / tmp1->next->n;
	tmp1->next->n = division;
	*stack = tmp1->next;
	free(tmp1);
}
