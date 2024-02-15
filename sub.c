#include "monty.h"

/**
 * sub - substract the top two elements of the stack
 * @stack: Double linked list
 * @line_number: Line counter
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp1;
	int subtract = 0;

	if (*stack == NULL || ((*stack)->prev == NULL && (*stack)->next == NULL))
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		free_stack(*stack);
		fclose(_close.file);
		free(_close.tmp);
		exit(EXIT_FAILURE);
	}
	tmp1 = *stack;
	subtract = tmp1->n - tmp1->next->n;
	tmp1->next->n = subtract;
	*stack = tmp1->next;
	free(tmp1);
}