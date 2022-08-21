#include "monty.h"

/**
 * op_pint - print the value at the top of the stack
 * @stack: list to print its top value
 * @line_number: line number where the opcode appear
 * Return: Nothing
 */
void op_pint(stack_t **stack, line_number)
{
	if ((*stack) == NULL)
	{
		fprintf(stderr, "L%d : can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
		print("%d\n", (*stack)->n);
}
