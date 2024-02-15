#include "monty.h"

/**
 * mul - s
 * @stack: Double linked list
 * @line_number: File line execution
 */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp1;
	int multiply = 0;

	if (*stack == NULL || ((*stack)->prev == NULL && (*stack)->next == NULL))
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free_stack(*stack);
		fclose(_close.file);
		free(_close.tmp);
		exit(EXIT_FAILURE);
	}
	tmp1 = *stack;
	multiply = tmp1->n * tmp1->next->n;
	tmp1->next->n = multiply;
	*stack = tmp1->next;
	free(tmp1);
}
