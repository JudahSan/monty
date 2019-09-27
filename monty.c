#include "monty.h"

/**
 * pall - Print all values on the stack
 * @stack: pointer to head of stack
 * @line_num: file's line number
 * Return: Void
 */

void pall(stack_t **stack, unsigned int line_num)
{
	*h = *stack;

	while (h->next)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}

/**
 * push - Pushes an element to the stack
 * @stack: pointer to head of stack
 * @line_number: file's line number
 * @n: variable
 * Return: address of new element
 */

stack_t *push(stack_t **stack, unsigned int line_number, int n)
{
	stack_t *new, *h = *stack;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
		return;

	new->prev == NULL;
	new->next == *stack;
	new->n = n;
	if (h->prev)
		h->prev = new;
	*stack = new;
	return (*stack);
}

/**
 * pop - Removes the top element of the stack
 * @stack: pointer to head of stack
 * @line_num: file's line number
 * Return: Void
 */

void pop(stack_t **stack, unsigned int line_num)
{
	stack_t *h;

	if (!(*stack))
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_num);
		exit(EXIT_FAILURE);
	}

	if (*h && (*h)->next)
	{
		*h = (*h)->next;
		free(*h);
		*stack = *h;
	}
}

/**
 * swap - Swaps the top two elements of the stack
 * @stack: pointer to head of stack
 * @line_num: file's line number
 * Return: Void
 */

void swap(stack_t **stack, unsigned int line_num)
{
	stack_t *h = *stack, *n;

	if (((*head) == NULL) || ((*head)->next == NULL))
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

	if (h && h->next)
	{
		n = *h->next;
		if (n->next->prev)
			n->next->prev = h;
		h->next = n->next;
		n->prev = NULL;
		n->next = h;
		h->prev = n;
	}
}
