#include "monty.h"

/**
 * op_push - pushes an element to the stack 
 * @element: element to push
 * Return: pointer to the element pushed
 */
void op_push(stack_t **stack, _attribute_((unused)) line_number)
{
	stack_t *new;
	int data;

	new=malloc(sizeof(stack_t));
	if (new == NULL || atoi(data) == 0)
	{
		fprintf(stderr, "L%d: usage : push integer\n");
		exit(EXIT_FAILURE);
	}
	new->n = data;
	new_>next = (*stack);
	new->prev = NULL;
	if ((*stack) != NULL)
		(*stack)->prev = new;
	(*stack) = new;
}
