#include "monty.h"

/**
 * op_pall - prints all the elements of the stack
 * @stack: list to print its elements
 * @line_number: line number
 * Return: Nothing
 */
void op_pall(stack_t **stack, _attribute_((unused)) line_number)
{
	while ((*stack) != NULL)
	{
		printf("%d\n", (*stack)->n);
		(*stack) = (*stack)->next;
	}
}
