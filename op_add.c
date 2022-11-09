#include "monty.h"

/**
 * op_add - adds the top two elements of the stack.
 * @stack: stack to add its top two elements.
 * @line_number: unused variable for the line number where add opcode appears
 * Return: Nothing
 */
void op_add(stack_t **stack, unsigned int line_number)
{
	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n += (*stack)->n;
	op_pop(stack, line_number);
}
