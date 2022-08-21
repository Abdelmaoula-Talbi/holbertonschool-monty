#include "monty.h"

/**
 * op_swap - swaps the top ewo elements of the stack
 * @stack: list to swap its two elements
 * @line_number: line number where the opcode swap appear
 * Return: Nothing
 */
void op_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*stack);
	(*stack)->next->prev = temp->prev;
	(*stack)->next->next = temp;
	(*stack)->next = temp->next->next;
	(*stack)->prev = temp->next;
	(*stack) = (*stack)->next;
}
