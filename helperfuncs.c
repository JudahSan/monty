#include "monty.h"

/**
 * _strcmp - compares strings
 * @opcode: a string to be compared
 * @list: a string to be compared
 * Return: 0
 */
int _strcmp(char *opcode, char *list)
{
	while (*list != '\0')
	{
		if (*list == ' ')
			list++;
		else if (*opcode == *list)
		{
			opcode++;
			list++;
			if (*opcode == '\0' && (*list == ' ' || *list == '\n' || *list == '\0'))
				return (1);
		}
		else
			return (0);
	}
	return (0);
}

/**
 * nlfind - finds newline
 * @nl - '\n'
 * @list: the string to find \n
 * Return: 1 || 0
 */
int nlfind(char *list)
{
	char *opcode = "\n";

	while (*list != '\0')
	{
		if (*opcode == *list)
		{
			opcode++;
			list++;
			if (*opcode == '\0')
				return (1);
		}
		else
			list++;
	}
	return (0);
}

/**
 * pushint - int for push opcode
 * @list: the content of the file
 * Return: the number
 */
int pushint(char *list, int ln)
{
	char *opcode = "push";
	int i = 0;
	
	while (*list != '\0')
	{
		if (*opcode == *list)
		{
			opcode++;
			list++;
			if (*opcode == '\0')
			{
				while (*list)
				{
					if ((*list >= '0' && *list <= '9') || *list == '-')
					{
						i = 1;
						while (list[i])
						{
							if ((list[i] >= '0' && list[i] <= '9') || list[i] == ' ')
								i++;
							else if (list[i] == '\0' || list[i] == '\n')
								break;
							else
							{
								fprintf(stderr, "L%d: usage: push integer\n", ln);
								exit(EXIT_FAILURE);
							}
						}
						return (atoi(list));
					}
					else if (*list == ' ')
						list++;
					else
					{
						fprintf(stderr, "L%d: usage: push integer\n", ln);
						exit(EXIT_FAILURE);
					}
				}
			}
		}
		else
			list++;
	}
	return (0);
}
