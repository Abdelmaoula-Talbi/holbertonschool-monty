#include "monty.h"

/**
 * add - adds 2 nodes of stack
 * @h: head of the stack
 * @ln: line number
 * Return: void
 */
void add(stack_t **h, unsigned int ln)
{
	unsigned int j;
	stack_t *k;

	if (*h == NULL || (*h)->next == NULL)
		{
			fprintf(stderr, "L%d: can't add, stack too short\n", ln);
			isFail = 1;
			return;


	k = (*h)->next;

	j = (*h)->n + k->n;

	k->n = j;

	pop(h, ln);
}
