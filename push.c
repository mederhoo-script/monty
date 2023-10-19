#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * push - Pushes a new node onto the stack.
 *
 * @stack: A pointer to the pointer to the stack.
 * @n: The value to be added to the new node.
 */
void push(stack_t **stack, int n)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new_node;

	*stack = new_node;
}
