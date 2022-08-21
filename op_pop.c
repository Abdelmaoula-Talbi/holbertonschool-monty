#include "monty.h"

/**
 * op_pop - delete the top element of the stack
 * @stack: list to delete its top element
 * @line_number:line number
 * Return: Nothing
 */
void op_pop(stack_t **stack, unsigned int line_number)
{
	if ((*stack) == NULL)
	{
		fprintf(stderr, "L%d: can't pop and empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->next != NULL)
		(*stack)->next->prev = (*stack)->prev;
	(*stack) = (*stack)->next;
}
