#include "monty.h"
#include <stdio.h>

/**
 * pall - Prints all the values on the stack, starting from the top.
 *
 * @stack: A pointer to the pointer to the stack.
 * @line_number: The line number in the Monty file (unused in this function).
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	(void)line_number;

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
