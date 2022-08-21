#include "monty.h"

/**
 * op_pop - delete the top element of the stack
 * @stack: list to delete its top element
 * @line_number:line number
 * Return: Nothing
 */
void op_pop(stack_t **stack, _attribute_((unused)) unsigned int line_number)
{
	if ((*stack) == NULL)
	{
		fprintf(stderr, "L%d: can't pop and empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->next->prev = (*stack)->prev;
			(*stack)->next->prev = (*stack)->prev;
	(*stack) = (*stack)->next;
}
