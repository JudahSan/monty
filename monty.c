#include "monty.h"

int main(int ac, char *av[])
{
	char *strop;
	int ln = 0, i = 0, fd;

	instruction_t st[] = {
		{"pall", pall},
		{"push", push},
		{"add", add},
		{"swap", swap},
		{"pop", pop},
		{"nop", NULL}
	}

	if (ac != 2)
		printf("not right ac");
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		printf("fail");
	read(fd, buf, numofstufftoread)

	while (st[i].opcode != "nop")
	{
		if (st[i].opcode == strop[])
		{
			str[i].f(stack, ln)
			{
				i love you <3
			}
		}
		i++;
	}
}

void pall(stack_t **stack, unsigned int line_number)
{
	*h = *stack;

	while (h->next)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}

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

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *h;
	if (*h && (*h)->next)
	{
		*h = (*h)->next;
		free(*h);
		*stack = *h;
	}
}

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *h = *stack, *n;
	
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