#include "monty.h"


int main(int ac, char *av[])
{
	char *buf = NULL, *string[100];
	int ln = 0, i = 0, fd, y;
	stack_t *ptr;
	stack_t *stack = NULL;

	instruction_t st[] = {
		{"pall", pall},
		{"add", add},
		{"swap", swap},
		{"pop", pop},
		{"nop", NULL}
	};

    if (ac != 2)
		printf("not right ac");
	
	//printf("%s\n", av[1]);

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
    {
            fprintf(stderr, "%s won't open", av[1]);
            exit(EXIT_FAILURE);
    }
	buf = malloc(1000);
    if (buf == NULL)
    {
        fprintf(stderr, "Malloc Failure");
        exit(EXIT_FAILURE);
    }

    y = read(fd, buf, 1000);
    if (y == -1)
        exit(EXIT_FAILURE);
	//printf("%s\n", buf);
    string[ln] = strtok(buf, "\n");
	while (string[ln++])
		string[ln] = strtok(NULL, "\n");
	
	for(ln = 0; string[ln]; ln++)
	{	
		if (_strcmp("push", string[ln]))
		{
			//printf("1: The Truth opcode %s == string %s on line %d the number %d\n", "push", string[ln], ln, pushint(string[ln]));
			push(&stack, ln, pushint(string[ln]));
		}
		else
		{	
			i = 0;
			while (st[i].opcode != "nop")
			{	
				if (_strcmp(st[i].opcode, string[ln]))
				{
					//printf("2: The Truth opcode %s == string %s on line %d\n", st[i].opcode, string[ln], ln);
					st[i].f(&stack, ln);
				}
				i++;
			}
		}
		//printf("3: the tokenizer worked -> %s\n", string[ln]);
	}

	i = 0;

	free(buf);
	close(fd);
	return (0);
}

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *h = *stack;

	//printf("here in pall %d\n", h->n);
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}

void push(stack_t **stack, unsigned int line_number, int n)
{
	stack_t *new, *h = *stack;

	if (stack == NULL)
	{
		printf("stack is NULL, *stack == NULL, were inside");
		exit(EXIT_FAILURE);
	}
	new = malloc(sizeof(stack_t));
	if (new == NULL)
		exit;
	new->prev = NULL;
	new->n = n;
	new->next = *stack;
	if (*stack)
		h->prev = new;
	*stack = new;
	//printf("new node -> %d\n", (*stack)->n);

}

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *h = *stack;
	if (h && (h)->next)
	{
		h = (h)->next;
		free(h);
		*stack = h;
	}
}

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *h = *stack, *n;
	
	if (h && h->next)
	{
		n = h->next;
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
		n = h->next;
		n->n += h->n;
		free(h);
		*stack = n;
	}
}