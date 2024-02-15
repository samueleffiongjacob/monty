#include "monty.h"


/**
 * pstr - s
 * @stack: Double linked list
 * @line_number: File line execution
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	(void) line_number;

	if (!stack || !*stack)
	{
		return;
	}
	while (tmp)
	{
		if (tmp->n == 0)
			break;
		if (tmp->n < 0 || tmp->n > 127)
		{
			break;
		}
		tmp = tmp->next;
		*stack = tmp->next;
	}
	free(tmp);
}
