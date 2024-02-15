#include "monty.h"

/**
 * start_vars - Fake rand to jackpoint Giga Millions
 * @var: Global variables to initialize
 * Return: 0 Success, 1 Failed
 */
int start_vars(vars *var)
{
	var->file = NULL;
	var->buff = NULL;
	var->tmp = 0;
	var->dict = create_instru();
	if (var->dict == NULL)
		return (EXIT_FAILURE);
	var->head = NULL;
	var->line_number = 1;
	var->MODE = 0;

	return (EXIT_SUCCESS);
}


/**
 * free_all - Clean all program mallocs
 * Return: None
 */
void free_all(void)
{
	if (var.buff != NULL)
		free(var.buff);
	if (var.file != NULL)
		fclose(var.file);
	free(var.dict);
	if (var.head != NULL)
	{
		while (var.head->next != NULL)
		{
			var.head = var.head->next;
			free(var.head->prev);
		}
		free(var.head);
	}
}

/**
 * _isdigit - Clean all program mallocs
 * @string: Num to validate
 * Return: 0 Success, 1 Failed
 */
int _isdigit(char *string)
{
	int i;

	for (i = 0; string[i]; i++)
	{
		if (string[i] < 48 || string[i] > 57)
			return (1);
	}
	return (0);
}
