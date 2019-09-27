#include "monty.h"

/**
 * fileman - open and read file
 * @fl_nm: File Name
 * @argmnts: Tokenized arguments
 * Return: void
 */

void fileman(char *fl_nm, char **argmnts)
{
	int x;
	int y = 1;
	char *cmd;

	x = open(fl_nm, O_RDONLY);

	if (x == -1)
	{
		fprintf(stderr, "%s won't open", fl_nm);
		exit(EXIT_FAILURE);
	}
	cmd = malloc(ARG_MAX * 1000);
	if (cmd == NULL)
	{
		fprintf(stderr, "Malloc Failure");
		exit(EXIT_FAILURE);
	}
	y = read(x, cmd, ARG_MAX * 1000);
	if (y == -1)
		exit(EXIT_FAILURE);

	tokenize(cmd, "\n", argmnts);
	free(cmd);
}

/**
 * main - Interprets monty bytecode
 * @ac: number of arguments
 * @av: array of arguments
 * Return: 0
 */

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
					i love you < 3
					}
			}
			i++;
		}
}
