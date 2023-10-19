#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
#include "monty.h"


/**
 * process_line - Process a single line of the file.
 * @line: The line to process.
 * @stack: The stack.
 * @line_number: The current line number.
 */
void process_line(char *line, stack_t **stack, unsigned int line_number)
{
	if (strcmp(line, "pall\n") == 0)
		pall(stack, line_number);
	else if (strncmp(line, "push ", 5) == 0)
		push(stack, atoi(line + 5));
	else if (strcmp(line, "pint\n") == 0)
		pint(stack, line_number);
	else if (strcmp(line, "pop\n") == 0)
		pop(stack, line_number);
	else if (strcmp(line, "swap\n") == 0)
		swap(stack, line_number);
	else if (strcmp(line, "add\n") == 0)
		add(stack, line_number);
	else if (strcmp(line, "nop\n") == 0)
	;
	else if (strcmp(line, "sub\n") == 0)
		sub(stack, line_number);
	else if (strcmp(line, "div\n") == 0)
		div_op(stack, line_number);
	else
	{
		fprintf(stderr, "L%d: unknown instruction %s", line_number, line);
		exit(EXIT_FAILURE);
	}
}

/**
 * cleanup_stack - Free the memory allocated for the stack.
 * @stack: The stack to clean up.
 */
void cleanup_stack(stack_t *stack)
{
	while (stack != NULL)
	{
		stack_t *temp;
		temp = stack;

		temp = stack->next;
		free(stack);
		stack = temp;
	}
}

/**
 * main - Monty interpreter main function.
 * @argc: The number of arguments.
 * @argv: An array of strings containing the arguments.
 * Return: 0 on success, EXIT_FAILURE on failure.
 */
int main(int argc, char *argv[])
{

	FILE *file;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	stack_t *stack = NULL;
	unsigned int line_number = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((read = getline(&line, &len, file)) != -1)
	{
		line_number++;
		process_line(line, &stack, line_number);
	}

	free(line);
	fclose(file);
	cleanup_stack(stack);
	return (0);
}
