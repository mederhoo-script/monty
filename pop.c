#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * pop - Removes the top element of the stack.
 *
 * @stack: A pointer to the pointer to the stack.
 * @line_number: The line number in the Monty file.
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;

	if (temp->next != NULL)
		temp->next->prev = NULL;

	*stack = temp->next;
	free(temp);
}
