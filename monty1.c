#include "monty.h"

/**
 * add - Adds the top two elements of the stack.
 * @stack: pointer to head of stack
 * @line_number: file's line number
 * Return: Void
 */

void add(stack_t **stack, unsigned int line_number)
{
	stack_t *h = *stack, *n;

	if (*stack && (*stack)->next)
	{
		n = *h->next;
		n->n += h->n;
		free(h);
		*stack = n;
	}
}
