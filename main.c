#include "monty.h"
/**
 * main - monty interperter
 * @ac: the number of arguments
 * @av: the arguments
 * return: 0
 */
int main(int ac, char *av[])
{
	char *buf = NULL, *string[100] = {NULL};
	int ln = 0, fd, y, x;
	stack_t *stack = NULL;

	if (ac != 2)
		printf("not right ac");
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
	for (x = 0; x < 1000; x++)
		buf[x] = '\0';
	y = read(fd, buf, 1000);
	if (y == -1)
		exit(EXIT_FAILURE);
	string[ln] = strtok(buf, "\n");
	while (string[ln++])
		string[ln] = strtok(NULL, "\n");

	execute(string, stack);
	free_stack(stack);
	free(buf);
	close(fd);
	return (0);
}

/**
 * execute - executes opcodes
 * @string: contents of file
 * @stack: the list
 * Return: void
 */
void execute(char *string[], stack_t *stack)
{
	int ln, i;

	instruction_t st[] = {
		{"pall", pall},
		{"pint", pint},
		{"add", add},
		{"swap", swap},
		{"pop", pop},
		{"nop", NULL}
	};

	for (ln = 0; string[ln]; ln++)
	{
		if (_strcmp("push", string[ln]))
			push(&stack, ln, pushint(string[ln]));
		else
		{
			i = 0;
			while (!_strcmp(st[i].opcode, "nop"))
			{
				if (_strcmp(st[i].opcode, string[ln]))
					st[i].f(&stack, ln);
				i++;
			}
		}
	}
}
